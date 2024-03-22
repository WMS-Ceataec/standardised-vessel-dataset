namespace Ceataec.StandardisedVesselDataset.Models;

/// <summary>
/// Represent the Fuel Consumption section of SVD
/// </summary>
public class FuelConsumption
{
    public double HfoConsumedTotal { get; init; }
    public double HfoConsumedByMe { get; init; }
    public double HfoConsumedByDg { get; init; }
    public double HfoConsumedByBoiler { get; init; }

    public double MdoConsumedTotal { get; init; }
    public double MdoConsumedByMe { get; init; }
    public double MdoConsumedByDg { get; init; }
    public double MdoConsumedByBoiler { get; init; }

    public double LsfoConsumedTotal { get; init; }
    public double LsfoConsumedByMe { get; init; }
    public double LsfoConsumedByDg { get; init; }
    public double LsfoConsumedByBoiler { get; init; }

    public double LsgoConsumedTotal { get; init; }
    public double LsgoConsumedByMe { get; init; }
    public double LsgoConsumedByDg { get; init; }
    public double LsgoConsumedByBoiler { get; init; }

    public double LpgButaneConsumedTotal { get; init; }
    public double LpgButaneConsumedByMe { get; init; }
    public double LpgButaneConsumedByDg { get; init; }
    public double LpgButaneConsumedByBoiler { get; init; }

    public double LpgPropaneConsumedTotal { get; init; }
    public double LpgPropaneConsumedByMe { get; init; }
    public double LpgPropaneConsumedByDg { get; init; }
    public double LpgPropaneConsumedByBoiler { get; init; }

    public double LngMethaneConsumedTotal { get; init; }
    public double LngMethaneConsumedByMe { get; init; }
    public double LngMethaneConsumedByDg { get; init; }
    public double LngMethaneConsumedByBoiler { get; init; }

    public double EthanolConsumedTotal { get; init; }
    public double EthanolConsumedByMe { get; init; }
    public double EthanolConsumedByDg { get; init; }
    public double EthanolConsumedByBoiler { get; init; }

    public double MethanolConsumedTotal { get; init; }
    public double MethanolConsumedByMe { get; init; }
    public double MethanolConsumedByDg { get; init; }
    public double MethanolConsumedByBoiler { get; init; }
}