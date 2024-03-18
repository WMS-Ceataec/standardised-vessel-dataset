/**
 * Represents the Sea Conditions section of SVD.
 */
export type SeaConditions = {
    SeaDirectionMagnetic: number
    SeaDirectionTrue: number
    SwellDirectionMagnetic: number
    SwellDirectionTrue: number
    WindDirectionMagnetic: number
    WindDirectionTrue: number
    BadWeatherHours: number
    BadWeatherDistance: number
    SeaHeight: number
    SwellHeight: number
    Current: number
}
