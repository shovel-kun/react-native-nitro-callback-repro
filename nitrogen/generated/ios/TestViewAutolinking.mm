///
/// TestViewAutolinking.mm
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#import <Foundation/Foundation.h>
#import <NitroModules/HybridObjectRegistry.hpp>
#import "TestView-Swift-Cxx-Umbrella.hpp"
#import <type_traits>

#include "HybridTestViewSpecSwift.hpp"

@interface TestViewAutolinking : NSObject
@end

@implementation TestViewAutolinking

+ (void) load {
  using namespace margelo::nitro;
  using namespace margelo::nitro::testview;

  HybridObjectRegistry::registerHybridObjectConstructor(
    "TestView",
    []() -> std::shared_ptr<HybridObject> {
      std::shared_ptr<margelo::nitro::testview::HybridTestViewSpec> hybridObject = TestView::TestViewAutolinking::createTestView();
      return hybridObject;
    }
  );
}

@end
