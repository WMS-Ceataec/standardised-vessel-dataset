import { EmissionsReporting } from './EmissionsReporting'
import { FuelConsumption } from './FuelConsumption'
import { FuelReceived } from './FuelReceived'
import { FuelRemaining } from './FuelRemaining'
import { General } from './General'
import { PortAndRouteInformation } from './PortAndRouteInformation'
import { SeaConditions } from './SeaConditions'
import { SpeedAndDistance } from './SpeedAndDistance'
import { Water } from './Water'
import { Weather } from './Weather'

/**
 * Represents the Standardised Vessel Dataset (SVD).
 * See more: https://smartmaritimenetwork.com/standardised-vessel-dataset-for-noon-reports/
 */
export type StandardisedVesselDataset = {
    General: General
    PortAndRouteInformation: PortAndRouteInformation
    SpeedAndDistance: SpeedAndDistance
    Weather: Weather
    SeaConditions: SeaConditions
    FuelRemaining: FuelRemaining
    Water: Water
    FuelConsumption: FuelConsumption
    FuelReceived: FuelReceived
    EmissionsReporting: EmissionsReporting
}
