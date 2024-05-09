import { ArrivalTimes } from './ArrivalTimes'
import { CargoInformation } from './CargoInformation'
import { CylinderLubeOilInformation } from './CylinderLubeOilInformation'
import { DeviationFromPlanned } from './DeviationFromPlanned'
import { ElectricityConsumption } from './ElectricityConsumption'
import { FreshWater } from './FreshWater'
import { FuelAndBunkerInformation } from './FuelAndBunkerInformation'
import { GeneralInformation } from './GeneralInformation'
import { PortInformation } from './PortInformation'
import { SpeedAndDistance } from './SpeedAndDistance'
import { WeatherInformation } from './WeatherInformation'

/**
 * Represents the Standardised Vessel Dataset (SVD).
 * See more: https://smartmaritimenetwork.com/standardised-vessel-dataset-for-noon-reports/
 */
export type StandardisedVesselDataset = {
    General: GeneralInformation
    PortInformation: PortInformation,
    ArrivalTimes: ArrivalTimes,
    DeviationFromPlanned: DeviationFromPlanned,
    SpeedAndDistance: SpeedAndDistance
    Weather: WeatherInformation,
    FreshWater: FreshWater,
    Cargo: CargoInformation,
    ElectricityConsumption: ElectricityConsumption,
    FuelAndBunker: FuelAndBunkerInformation,
    CylinderLubeOil : CylinderLubeOilInformation
}
