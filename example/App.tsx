import React from 'react';
import {Text, View, StyleSheet, Pressable, Button} from 'react-native';
import {TestView} from 'react-native-test-view';

function App(): React.JSX.Element {
  const [dimensions, setDimensions] = React.useState<{
    height: number;
    width: number;
  }>({
    height: 0,
    width: 0,
  });

  const [isRed, setIsRed] = React.useState(true);
  const [isAutoToggle, setIsAutoToggle] = React.useState(false); // New state for auto-toggle

  React.useEffect(() => {
    let intervalId: NodeJS.Timeout | null = null;

    if (isAutoToggle) {
      intervalId = setInterval(() => {
        setIsRed(prevIsRed => !prevIsRed);
      }, 1000);
    }

    return () => {
      if (intervalId) {
        clearInterval(intervalId);
      }
    };
  }, [isAutoToggle]); // Dependency array now includes isAutoToggle

  const toggleRed = () => {
    setIsRed(prevIsRed => !prevIsRed);
  };

  const toggleAutoToggle = () => {
    setIsAutoToggle(prevIsAutoToggle => !prevIsAutoToggle);
  };

  return (
    <View style={styles.container}>
      <TestView
        isRed={isRed}
        style={styles.view}
        onColorChange={{
          f: () => {
            console.log('color changed');
            console.log(dimensions);
          },
        }}
        onLayout={e => {
          console.log('layout changed');
          const {height, width} = e.nativeEvent.layout;
          console.log(height, width);
          setDimensions({height, width});
        }}
        onTouchStart={e => {
          console.log('touch started');
          console.log(dimensions);
        }}
      />

      <Button title="Toggle Red" onPress={toggleRed} />
      <Button
        title={isAutoToggle ? 'Stop Auto Toggle' : 'Start Auto Toggle'}
        onPress={toggleAutoToggle}
      />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
  view: {
    width: 200,
    height: 200,
  },
});

export default App;
