import type {
  HybridView,
  HybridViewProps,
  HybridViewMethods,
} from 'react-native-nitro-modules'

export interface TestViewProps extends HybridViewProps {
  isRed: boolean
  onColorChange: () => void
}

export interface TestViewMethods extends HybridViewMethods {}

export type TestView = HybridView<
  TestViewProps,
  TestViewMethods,
  { ios: 'swift'; android: 'kotlin' }
>

