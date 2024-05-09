/**
 * Represents the "Weather Information" section of SVD.
 */
export type WeatherInformation = {
    /**
     * Brief details of weather and sea conditions prevailing.
     */
    WeatherRemarks: string;

    /**
     * Duration, in hours, during which the weather conditions are unfavourable or challenging in sea state above Beaufort scale 4 (manual observation).
     */
    BadWeatherHours: number;

    /**
     * Number of nautical miles experienced when sea state above Beaufort scale 4 (manual observation).
     */
    BadWeatherDistance: number;

    /**
     * Force of wind on Beaufort Scale as measured by on board ship weather station, over the time of reporting (scale from 0-12).
     */
    WindForce: number;

    /**
     * Code indicating the wind speed, in units indicated in Iw.
     */
    WindSpeed: string;

    /**
     * Code indicating the true direction, in tens of degrees, from which wind is blowing (or will blow).
     */
    WindDirection: string;

    /**
     * Best estimate of the direction of wind relative to the ship, in degrees, made by the seafarer on board.
     */
    WindDirectionEstimatedRelative: number;

    /**
     * Best estimate of the direction of wind relative to the ship, in degrees true, made by the seafarer on board.
     */
    WindDirectionEstimated: number;

    /**
     * Measure of air temperature in degrees Celsius at ship location.
     */
    AirTemperature: number;

    /**
     * Measure of the barometric pressure of the ship environment, in bars.
     */
    AtmosphericPressure: number;

    /**
     * Code indicating the state of the sea by significant wave height.
     */
    StateOfSea: string;

    /**
     * Best estimate of the direction of sea relative to the ship, in degrees, made by the seafarer on board.
     */
    SeaDirectionRelative: number;

    /**
     * Best estimate of the direction of sea, in degrees true, made by the seafarer on board.
     */
    SeaDirection: number;

    /**
     * Recorded sea height in metres (as per weather provider).
     */
    SeaHeight: number;

    /**
     * Best estimate of the direction of swell relative to the ship, in degrees, made by the seafarer on board.
     */
    SwellDirectionRelative: number;

    /**
     * Best estimate of the direction of swell, in degrees true, made by the seafarer on board.
     */
    SwellDirection: number;

    /**
     * Recorded swell height in metres (as per weather provider).
     */
    SwellHeight: number;

    /**
     * Best estimate of the direction of ocean current relative to the ship, in degrees, made by the seafarer on board.
     */
    OceanCurrentDirectionRelative: number;

    /**
     * Best estimate of the direction of ocean current, in degrees true, made by the seafarer on board.
     */
    OceanCurrentDirection: number;

    /**
     * Direction of ocean current, in degrees, as per weather provider, if different.
     */
    OceanCurrentDirectionWeatherProvider: number;
};
