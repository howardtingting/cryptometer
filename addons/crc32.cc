#include <node.h>
#include "../cpp_srcs/crc32.h"

CRC32 crc32;

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

void crc32_fn(const FunctionCallbackInfo<Value>& args) {

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
  const char* crc32Input = ToCString(str);
  std::string crc32HashStr = crc32(crc32Input);
  const char* crc32HashVal = &*crc32HashStr.begin();

  args.GetReturnValue().Set(String::NewFromUtf8(isolate, crc32HashVal));
}

void CreateFunction(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  Local<Context> context = isolate->GetCurrentContext();
  Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, crc32_fn);
  Local<Function> fn = tpl->GetFunction(context).ToLocalChecked();

  // omit this to make it anonymous
  fn->SetName(String::NewFromUtf8(
      isolate, "crc32"));

  args.GetReturnValue().Set(fn);
}

void Init(Local<Object> exports, Local<Object> module) {
  NODE_SET_METHOD(module, "exports", CreateFunction);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}  // namespace demo
