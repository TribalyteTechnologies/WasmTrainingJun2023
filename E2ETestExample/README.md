# E2eTestingExample

### This is a simple example of how to do an E2E test with the cypress tool. https://www.cypress.io/

The following example presents some of the functions provided by the cypress tool to do an E2E test in one of the examples developed with WebAssembly technology.

In this example we will see how the fields of a form are filled, how the press of a button is simulated and how the information returned by the browser console is captured. The checks that are made are: the form fields are filled correctly, and the data received by the console is what expected.

To run the test

we can use the docker-compose located in this directory that will use Docker images from Apache (version 2.4) to launch the web and Cypress (version 12.11.0). 

To use the docker-compose we can execute:

```shell
docker-compose -f docker-compose.yml up --abort-on-container-exit
```

The most important file is the "spec.cy.js" file where all the steps that the test must execute are configured, can be found in the folder /cypress/e2e