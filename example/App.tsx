import React from 'react';
import { Text, View, StyleSheet } from 'react-native';
import { TestView } from 'react-native-test-view';

function App(): React.JSX.Element {
  return (
    <View style={styles.container}>
        <TestView isRed={true} style={styles.view} />
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
    height: 200
  }});

export default App;