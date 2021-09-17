#include <node.h>

namespace demo {

using v8::Exception;
using v8::Context;
using v8::Function;
using v8::FunctionCallbackInfo;
using v8::FunctionTemplate;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

const char* ToCString(const String::Utf8Value& value) {
  return *value ? *value : "<string conversion failed>";
}

void md5(const FunctionCallbackInfo<Value>& args) {

  Isolate* isolate = args.GetIsolate();

  //Check # args
  if (args.Length() != 1) {
    //Throw an Error that is passed back to Javascript
    isolate->ThrowException(Exception::TypeError(
      String::NewFromUtf8(isolate, "Invalid argument count.")));
    return;
  }

  //Check arg types
  if (!args[0]->IsString()) {
    isolate->ThrowException(Exception::TypeError(
      String::NewFromUtf8(isolate, "Invalid Type: Argument must be string")));
    return;
  }

  String::Utf8Value str(args[0]);
  const char* md5HashVal = ToCString(str);
 //     args[0].As<Number>()->Value() + args[1].As<Number>()->Value();
 // Local<Number> num = Number::New(isolate, value);

  args.GetReturnValue().Set(String::NewFromUtf8(isolate, md5HashVal));
}

void CreateFunction(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  Local<Context> context = isolate->GetCurrentContext();
  Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, md5);
  Local<Function> fn = tpl->GetFunction(context).ToLocalChecked();

  // omit this to make it anonymous
  fn->SetName(String::NewFromUtf8(
      isolate, "md5"));

  args.GetReturnValue().Set(fn);
}

void Init(Local<Object> exports, Local<Object> module) {
  NODE_SET_METHOD(module, "exports", CreateFunction);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}  // namespace demo
