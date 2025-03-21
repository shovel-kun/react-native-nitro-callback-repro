#include <jni.h>
#include "TestViewOnLoad.hpp"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void*) {
  return margelo::nitro::testview::initialize(vm);
}
