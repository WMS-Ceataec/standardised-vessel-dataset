## Installation

**Npm**

```bash
npm install standardised-vessel-dataset
```

**Yarn**

```bash
yarn add standardised-vessel-dataset
```

## Usage

To get started with the library, you can use the following code snippet:

```typescript
import { GeneralInformation, PortInformation } from 'standardised-vessel-dataset'

function App() {
    const general: GeneralInformation = {
        EventType: 'Noon Report'
        OperationType: 'Sailing',
        ShipReportingDate: new Date('2024-03-04T10:00:00Z'),
        ShipName: 'Ship name',
        Imo: '1234567',
        ShipType: 'Container Ship',
        VoyageNumber: 'Voy123',
        VoyageLegIdentifier: 'Leg1',
        VoyageLegRemarks: 'Some remarks about the vessel',
    }

    const portInfo: PortInformation = {
        DeparturePortCode: 'BCN',
        DeparturePortDescription: 'Barcelona, Spain',
        ArrivalPortCode: 'LIS',
        ArrivalPortDescription: 'Lisbon, Portugal'
        DepartureDateTime: new Date('2024-03-05T12:00:00Z')
    }
}
```
