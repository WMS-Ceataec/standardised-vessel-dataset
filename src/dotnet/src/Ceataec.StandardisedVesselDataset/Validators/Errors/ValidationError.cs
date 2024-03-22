namespace Ceataec.StandardisedVesselDataset.Validators.Errors;

/// <summary>
/// Represents a validation error.
/// </summary>
/// <param name="PropertyName">The property name.</param>
/// <param name="Message">The error message.</param>
public record ValidationError(string PropertyName, string Message);