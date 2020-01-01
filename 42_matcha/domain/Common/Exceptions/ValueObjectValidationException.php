<?php

namespace Domain\Common\Exceptions;

use Exception;

class ValueObjectValidationException extends Exception
{
    public static function throwWith(string $value, string $valueObjectClassName) {
        throw new self("Value \"{$value}\" violates validation rules for {$valueObjectClassName}");
    }
}
