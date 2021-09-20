#include <node.h>
#include "../cpp_srcs/sha3.h"

SHA3 sha3;

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

void sha3_fn(const FunctionCallbackInfo<Value>& args) {

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
  const char* sha3Input = ToCString(str);
  std::string sha3HashStr = sha3(sha3Input);
  const char* sha3HashVal = &*sha3HashStr.begin();

  args.GetReturnValue().Set(String::NewFromUtf8(isolate, sha3HashVal));
}

void CreateFunction(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  Local<Context> context = isolate->GetCurrentContext();
  Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, sha3_fn);
  Local<Function> fn = tpl->GetFunction(context).ToLocalChecked();

  // omit this to make it anonymous
  fn->SetName(String::NewFromUtf8(
      isolate, "sha3"));

  args.GetReturnValue().Set(fn);
}

void Init(Local<Object> exports, Local<Object> module) {
  NODE_SET_METHOD(module, "exports", CreateFunction);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}  // namespace demo
