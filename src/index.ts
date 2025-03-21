import { getHostComponent, type HybridRef } from 'react-native-nitro-modules'
import TestViewConfig from '../nitrogen/generated/shared/json/TestViewConfig.json'
import type {
  TestViewProps,
  TestViewMethods,
} from './views/test-view.nitro'


export const TestView = getHostComponent<TestViewProps, TestViewMethods>(
  'TestView',
  () => TestViewConfig
)

export type TestViewRef = HybridRef<TestViewProps, TestViewMethods>
