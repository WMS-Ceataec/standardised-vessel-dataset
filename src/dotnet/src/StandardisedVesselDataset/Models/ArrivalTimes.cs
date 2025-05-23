namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represents the "Arrival Times" section of the SVD.
/// </summary>
public class ArrivalTimes
{
    /// <summary>
    /// The date and time the ship arrives at a specified location (Actual Time of Arrival, ATA).
    /// </summary>
    public DateTime Arrival { get; init; }

    /// <summary>
    /// The date and time the ship departs from a specified location (Actual Time of Departure, ATD).
    /// </summary>
    public DateTime Departure { get; init; }

    /// <summary>
    /// The date and time the ship estimates to reach the specified location in port (Estimated Time of Arrival, ETA).
    /// </summary>
    public DateTime LocationEta { get; init; }

    /// <summary>
    /// The actual date and time the ship actually reached the specified location in port.
    /// </summary>
    public DateTime LocationActual { get; init; }

    /// <summary>
    /// The date and time the ship estimates to reach the Pilot Boarding Place.
    /// </summary>
    public DateTime PilotBoardingPlaceEta { get; init; }

    /// <summary>
    /// The actual date and time the ship actually reached the Pilot Boarding Place.
    /// </summary>
    public DateTime PilotBoardingPlaceActual { get; init; }

    /// <summary>
    /// The date and time the ship estimates to reach the VTS (Vessel Traffic Service) area.
    /// </summary>
    public DateTime VtsEta { get; init; }

    /// <summary>
    /// The actual date and time the ship actually reached the VTS (Vessel Traffic Service) area.
    /// </summary>
    public DateTime VtsActual { get; init; }

    /// <summary>
    /// The date and time the ship is estimated to arrive at the next port of call.
    /// </summary>
    public DateTime NextPortEta { get; init; }

    /// <summary>
    /// Travel time from departed port to destination port in hours.
    /// </summary>
    public int VoyageTime { get; init; }
}