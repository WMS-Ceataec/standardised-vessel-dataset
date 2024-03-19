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
import { General, PortAndRouteInformation } from 'standardised-vessel-dataset'

function App() {
    const general: General = {
        Position: 'Position',
        Time: new Date('2024-03-04T10:00:00Z'),
        VesselName: 'MV Example',
        Imo: '1234567',
        ShipType: 'Container Ship',
        VoyageNumber: 'Voy123',
        Leg: 'Leg1',
        Remarks: 'Some remarks about the vessel',
    }

    const portInfo: PortAndRouteInformation = {
        DeparturePort: 'Port A',
        DepartureTime: new Date('2024-03-01T08:00:00Z'),
        DestinationPort: 'Port B',
        Etapbp: new Date('2024-03-05T12:00:00Z'),
        EtaBerth: new Date('2024-03-05T14:00:00Z'),
        Etavts: new Date('2024-03-06T08:00:00Z'),
        DistanceToNextWaypointNm: 100,
        DistanceToNextWaypointKm: 185.2,
        DistanceToDestinationPortNm: 500,
        DistanceToDestinationPortKm: 926,
        ProjectedSpeedKn: 15,
        ProjectedSpeedKmh: 27.78,
        VoyageTimeMs: 259200000, // 3 days in milliseconds
    }
}
```



