namespace StandardisedVesselDataset.Models;

/// <summary>
/// Represent the Emission Reporting section of SVD
/// </summary>
public class EmissionsReporting
{
    public double Co2EmissionFactorMdo { get; init; }
    public double Co2EmissionFactorHfo { get; init; }
    public double Co2EmissionFactorLsfo { get; init; }
    public double Co2EmissionFactorLsgo { get; init; }
    public double Co2EmissionFactorLpgButane { get; init; }
    public double Co2EmissionFactorLpgPropane { get; init; }
    public double Co2EmissionFactorLngMethane { get; init; }
    public double Co2EmissionFactorEthanol { get; init; }
    public double Co2EmissionFactorMethanol { get; init; }
    public double CargoCarriedTons { get; init; }
    public double CargoCarriedCbm { get; init; }
    public double CargoCarriedStandardUnits { get; init; }
}