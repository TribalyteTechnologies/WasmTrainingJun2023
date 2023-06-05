import { IonContent, IonHeader, IonPage, IonTitle, IonToolbar, IonButton, IonList, IonItem, IonInput, IonLabel, IonToast, InputCustomEvent } from '@ionic/react';
import './Tab1.css';
import {useState} from 'react';

type IonicReactExampleType = {
  new(...args: any): IonicReactExampleType,
  setPersonalData(name: string, email: string, msg: string): string,
  delete(): void
}

declare var Module: {
  IonicReactExample: IonicReactExampleType
};

const Tab1: React.FC = () => {

  const [inputName, setInputName] = useState('');
  const [inputEmail, setInputEmail] = useState('');
  const [inputMessage, setInputMessage] = useState('');
  const [outputMessage, setOutputMessage] = useState('');
  const [showLabel, setShowLabel] = useState(false);
  const [isOpen, setIsOpen] = useState(false);

  const handleNameChange = (event: InputCustomEvent) => {
    setInputName(String(event.target.value));
  };

  const handleEmailChange = (event: InputCustomEvent) => {
    setInputEmail(String(event.target.value));
  };

  const handleMessageChange = (event: InputCustomEvent) => {
    setInputMessage(String(event.target.value));
  };

  const hideLabel = () => {
    setShowLabel(false);
  }

  const setPersonalData = () => {   
    try {
      let instance = new Module.IonicReactExample();
      setOutputMessage(instance.setPersonalData(inputName, inputEmail, inputMessage));
      setShowLabel(true);
      setTimeout(hideLabel, 5000);
      instance.delete();
    } catch (e: any){
      setIsOpen(true);
    }
  }

  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle>Tribalyte</IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent fullscreen>
        <IonHeader collapse="condense">
          <IonToolbar>
            <IonTitle size="large">Tab 1</IonTitle>
          </IonToolbar>
        </IonHeader>
        <IonList>
          <IonItem>
            <IonInput label="Name" placeholder="Enter your name" value={inputName} onIonChange={handleNameChange}></IonInput>  
          </IonItem>
          <IonItem>
            <IonInput label="Email" type="email" placeholder="Enter your email" value={inputEmail} onIonChange={handleEmailChange}></IonInput>       
          </IonItem>
          <IonItem>
            <IonInput label="Message" placeholder="Write your message" value={inputMessage} onIonChange={handleMessageChange}></IonInput>
          </IonItem>
        </IonList>
        <IonButton onClick={setPersonalData} id="present-alert" color="success">Send Message</IonButton>
        {showLabel && <IonItem color="success">
          <IonLabel> {outputMessage} </IonLabel>
        </IonItem>}
        <IonToast
          isOpen={isOpen}
          message="Object Module is not found"
          onDidDismiss={() => setIsOpen(false)}
          duration={5000}
        ></IonToast>
      </IonContent>
    </IonPage>
  );
};

export default Tab1;
