describe('template spec', () => {
  
  Cypress.on('uncaught:exception', (err, runnable) => {
    return false;
  });
  it('passes', () => {
    cy.visit('http://apacheserver/e2eExample.html', {
      onBeforeLoad(win) {
        cy.stub(win.console, 'log').as('consoleLog')
      },
    })
    cy.get('[for="message"]').should('contain', 'Message:')
    cy.get('[id="message"]').type('test message').should('have.value', 'test message')
    cy.get('[id="mail"]').type('fake@email.com').should('have.value', 'fake@email.com')
    cy.get('[id="lastname"]').type('Exposito Jimenez').should('have.value', 'Exposito Jimenez')
    cy.get('[id="name"]').type('Eugenio').should('have.value', 'Eugenio')
 
    cy.get('[id="sendbtn"]').click()
    cy.get('@consoleLog').should('be.calledWith', 'Message: test message')
    cy.get('@consoleLog').should('be.calledWith', 'Name: Eugenio')
    cy.get('@consoleLog').should('be.calledWith', 'Last name: Exposito Jimenez')
    cy.get('@consoleLog').should('be.calledWith', 'Mail: fake@email.com')
    cy.get('[id="return"]').should('have.value', 'The message has been sent')
  })
})
