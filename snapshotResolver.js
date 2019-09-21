module.exports = {
  // resolves from test to snapshot path
  resolveSnapshotPath: (testPath, snapshotExtension) => {
    return testPath.replace('lib/js/__tests__', '__snapshots__') + snapshotExtension;
  },

  // resolves from snapshot to test path
  resolveTestPath: (snapshotFilePath, snapshotExtension) => {
    return snapshotFilePath
      .replace('__snapshots__', 'lib/js/__tests__')
      .slice(0, -snapshotExtension.length);
  },

  // Example test path, used for preflight consistency check of the implementation above
  testPathForConsistencyCheck: 'some/__tests__/example.test.js',
};
