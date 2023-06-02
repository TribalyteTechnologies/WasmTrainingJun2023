describe('template spec', () => {
  
  Cypress.on('uncaught:exception', (err, runnable) => {
    cy.log('There was an error starting the test. Error: ', err.message)
    return false;
  });
  it('passes', () => {
    cy.visit('http://apacheserver/e2eTestThreadExample.html', {
      onBeforeLoad(win) {
        cy.stub(win.console, 'log').as('consoleLog')
      },
    })
    cy.get('@consoleLog').should('be.calledWith', 'Main thread')
    cy.get('@consoleLog').should('be.calledWith', 'Thread number: 1')
    cy.get('@consoleLog').should('be.calledWith', 'Thread number: 2')    
  })
})