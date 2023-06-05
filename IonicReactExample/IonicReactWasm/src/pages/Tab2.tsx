import { IonContent, IonHeader, IonPage, IonTitle, IonToolbar, IonButton, IonList, IonItem, IonInput, IonLabel, IonToast, InputCustomEvent } from '@ionic/react';
import './Tab2.css';
import {useState} from 'react';

type IonicReactExampleType = {
  new(...args: any): IonicReactExampleType,
  additionOfNumbers(firstNumber: number, secondNumber: number): number,
  delete(): void
}

declare var Module: {
  IonicReactExample: IonicReactExampleType
};

const Tab2: React.FC = () => {
  
  const [firstNumber, setFirstNumber] = useState(0);
  const [secondNumber, setSecondNumber] = useState(0);
  const [result, setResult] = useState(0);
  const [isOpen, setIsOpen] = useState(false);

  const handleFirstNumberChange = (event: InputCustomEvent) => {
    setFirstNumber(Number(event.target.value));
  };

  const handleSecondNumberChange = (event: InputCustomEvent) => {
    setSecondNumber(Number(event.target.value));
  };

  const addictionOfNums = () => {   
    try {
      let instance = new Module.IonicReactExample();
      setResult(instance.additionOfNumbers(Number(firstNumber), Number(secondNumber)));
      instance.delete();
    } catch (e: any){
      setIsOpen(true);
    }
  }

  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle>Addition of numbers</IonTitle>
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
            <IonInput label="Number 1" type="number" value={firstNumber} onIonChange={handleFirstNumberChange}></IonInput>  
          </IonItem>
          <IonItem>
            <IonInput label="Number 2" type="number" value={secondNumber} onIonChange={handleSecondNumberChange}></IonInput>
          </IonItem>
        </IonList>
        <IonButton onClick={addictionOfNums} id="present-alert" color="primary">Sum</IonButton>
        <IonLabel> {result} </IonLabel>
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

export default Tab2;
