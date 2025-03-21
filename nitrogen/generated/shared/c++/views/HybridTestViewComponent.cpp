///
/// HybridTestViewComponent.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "HybridTestViewComponent.hpp"

#include <string>
#include <exception>
#include <utility>
#include <NitroModules/NitroDefines.hpp>
#include <NitroModules/JSIConverter.hpp>
#include <react/renderer/core/RawValue.h>
#include <react/renderer/core/ShadowNode.h>
#include <react/renderer/core/ComponentDescriptor.h>
#include <react/renderer/components/view/ViewProps.h>

namespace margelo::nitro::testview::views {

  extern const char HybridTestViewComponentName[] = "TestView";

  HybridTestViewProps::HybridTestViewProps(const react::PropsParserContext& context,
                                           const HybridTestViewProps& sourceProps,
                                           const react::RawProps& rawProps):
    react::ViewProps(context, sourceProps, rawProps, filterObjectKeys),
    isRed([&]() -> CachedProp<bool> {
      try {
        const react::RawValue* rawValue = rawProps.at("isRed", nullptr, nullptr);
        if (rawValue == nullptr) return sourceProps.isRed;
        const auto& [runtime, value] = (std::pair<jsi::Runtime*, jsi::Value>)*rawValue;
        return CachedProp<bool>::fromRawValue(*runtime, value, sourceProps.isRed);
      } catch (const std::exception& exc) {
        throw std::runtime_error(std::string("TestView.isRed: ") + exc.what());
      }
    }()),
    onColorChange([&]() -> CachedProp<std::function<void()>> {
      try {
        const react::RawValue* rawValue = rawProps.at("onColorChange", nullptr, nullptr);
        if (rawValue == nullptr) return sourceProps.onColorChange;
        const auto& [runtime, value] = (std::pair<jsi::Runtime*, jsi::Value>)*rawValue;
        return CachedProp<std::function<void()>>::fromRawValue(*runtime, value.asObject(*runtime).getProperty(*runtime, "f"), sourceProps.onColorChange);
      } catch (const std::exception& exc) {
        throw std::runtime_error(std::string("TestView.onColorChange: ") + exc.what());
      }
    }()),
    hybridRef([&]() -> CachedProp<std::optional<std::function<void(const std::shared_ptr<margelo::nitro::testview::HybridTestViewSpec>& /* ref */)>>> {
      try {
        const react::RawValue* rawValue = rawProps.at("hybridRef", nullptr, nullptr);
        if (rawValue == nullptr) return sourceProps.hybridRef;
        const auto& [runtime, value] = (std::pair<jsi::Runtime*, jsi::Value>)*rawValue;
        return CachedProp<std::optional<std::function<void(const std::shared_ptr<margelo::nitro::testview::HybridTestViewSpec>& /* ref */)>>>::fromRawValue(*runtime, value.asObject(*runtime).getProperty(*runtime, "f"), sourceProps.hybridRef);
      } catch (const std::exception& exc) {
        throw std::runtime_error(std::string("TestView.hybridRef: ") + exc.what());
      }
    }()) { }

  HybridTestViewProps::HybridTestViewProps(const HybridTestViewProps& other):
    react::ViewProps(),
    isRed(other.isRed),
    onColorChange(other.onColorChange),
    hybridRef(other.hybridRef) { }

  bool HybridTestViewProps::filterObjectKeys(const std::string& propName) {
    switch (hashString(propName)) {
      case hashString("isRed"): return true;
      case hashString("onColorChange"): return true;
      case hashString("hybridRef"): return true;
      default: return false;
    }
  }

  HybridTestViewComponentDescriptor::HybridTestViewComponentDescriptor(const react::ComponentDescriptorParameters& parameters)
    : ConcreteComponentDescriptor(parameters,
                                  react::RawPropsParser(/* enableJsiParser */ true)) {}

  react::Props::Shared HybridTestViewComponentDescriptor::cloneProps(const react::PropsParserContext& context,
                                                                     const react::Props::Shared& props,
                                                                     react::RawProps rawProps) const {
    // 1. Prepare raw props parser
    rawProps.parse(rawPropsParser_);
    // 2. Copy props with Nitro's cached copy constructor
    return HybridTestViewShadowNode::Props(context, /* & */ rawProps, props);
  }

#ifdef ANDROID
  void HybridTestViewComponentDescriptor::adopt(react::ShadowNode& shadowNode) const {
    // This is called immediately after `ShadowNode` is created, cloned or in progress.
    // On Android, we need to wrap props in our state, which gets routed through Java and later unwrapped in JNI/C++.
    auto& concreteShadowNode = dynamic_cast<HybridTestViewShadowNode&>(shadowNode);
    const HybridTestViewProps& props = concreteShadowNode.getConcreteProps();
    HybridTestViewState state;
    state.setProps(props);
    concreteShadowNode.setStateData(std::move(state));
  }
#endif

} // namespace margelo::nitro::testview::views
