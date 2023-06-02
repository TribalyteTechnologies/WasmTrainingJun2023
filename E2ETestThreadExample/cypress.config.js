module.exports = {
  e2e: {
    setupNodeEvents(on, config) {
      on('before:browser:launch', (browser = {}, launchOptions) => {
        if (browser.family === 'chromium' && browser.name !== 'electron') {
          launchOptions.args.push('--enable-features=SharedArrayBuffer')
        }
        return launchOptions
      })
    },
    supportFile: false,
  },
};