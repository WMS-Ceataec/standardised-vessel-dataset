namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represent the "Weather Information" section of SVD
/// </summary>
public class WeatherInformation
{
    /// <summary>
    /// Brief details of weather and sea conditions prevailing.
    /// </summary>
    public string WeatherRemarks { get; init; }

    /// <summary>
    /// Duration, in hours, during which the weather conditions are unfavourable or challenging in sea state above Beaufort scale 4 (manual observation).
    /// </summary>
    public double BadWeatherHours { get; init; }

    /// <summary>
    /// Number of nautical miles experienced when sea state above Beaufort scale 4 (manual observation).
    /// </summary>
    public double BadWeatherDistance { get; init; }

    /// <summary>
    /// Force of wind on Beaufort Scale as measured by on board ship weather station, over the time of reporting (scale from 0-12).
    /// </summary>
    public int WindForce { get; init; }

    /// <summary>
    /// Code indicating the wind speed, in units indicated in Iw.
    /// </summary>
    public string WindSpeed { get; init; }

    /// <summary>
    /// Code indicating the true direction, in tens of degrees, from which wind is blowing (or will blow).
    /// </summary>
    public string WindDirection { get; init; }

    /// <summary>
    /// Best estimate of the direction of wind relative to the ship, in degrees, made by the seafarer on board.
    /// </summary>
    public double WindDirectionEstimatedRelative { get; init; }

    /// <summary>
    /// Best estimate of the direction of wind relative to the ship, in degrees true, made by the seafarer on board.
    /// </summary>
    public double WindDirectionEstimated { get; init; }

    /// <summary>
    /// Measure of air temperature in degrees Celsius at ship location.
    /// </summary>
    public double AirTemperature { get; init; }

    /// <summary>
    /// Measure of the barometric pressure of the ship environment, in bars.
    /// </summary>
    public double AtmosphericPressure { get; init; }

    /// <summary>
    /// Code indicating the state of the sea by significant wave height.
    /// </summary>
    public string StateOfSea{ get; init; }

    /// <summary>
    /// Best estimate of the direction of sea relative to the ship, in degrees, made by the seafarer on board.
    /// </summary>
    public double SeaDirectionRelative { get; init; }

    /// <summary>
    /// Best estimate of the direction of sea, in degrees true, made by the seafarer on board.
    /// </summary>
    public double SeaDirection { get; init; }

    /// <summary>
    /// Recorded sea height in metres (as per weather provider).
    /// </summary>
    public double SeaHeight { get; init; }

    /// <summary>
    /// Best estimate of the direction of swell relative to the ship, in degrees, made by the seafarer on board.
    /// </summary>
    public double SwellDirectionRelative { get; init; }

    /// <summary>
    /// Best estimate of the direction of swell, in degrees true, made by the seafarer on board.
    /// </summary>
    public double SwellDirection { get; init; }

    /// <summary>
    /// Recorded swell height in metres (as per weather provider).
    /// </summary>
    public double SwellHeight { get; init; }

    /// <summary>
    /// Best estimate of the direction of ocean current relative to the ship, in degrees, made by the seafarer on board.
    /// </summary>
    public double OceanCurrentDirectionRelative { get; init; }

    /// <summary>
    /// Best estimate of the direction of ocean current, in degrees true, made by the seafarer on board.
    /// </summary>
    public double OceanCurrentDirection { get; init; }

    /// <summary>
    /// Direction of ocean current, in degrees, as per weather provider, if different.
    /// </summary>
    public double OceanCurrentDirectionWeatherProvider { get; init; }
}
