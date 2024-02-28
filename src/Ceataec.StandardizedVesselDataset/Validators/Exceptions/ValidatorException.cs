﻿using Ceataec.StandardizedVesselDataset.Validators.Errors;

namespace Ceataec.StandardizedVesselDataset.Validators.Exceptions;

public class ValidatorException(IEnumerable<ValidationError> errors) : Exception(message: BuildErrorMessage(errors))
{
    private static string BuildErrorMessage(IEnumerable<ValidationError> errors)
    {
        var message = errors.Select(e => $"{Environment.NewLine} -- {e.PropertyName}: {e.Message}");
        return "Validation failed: " + string.Join(";", message);
    }
}