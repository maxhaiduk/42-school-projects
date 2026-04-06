<?php

namespace Domain\Common;

use Domain\Common\Exceptions\ValueObjectValidationException;
use Illuminate\Support\Facades\Validator;

abstract class ValueObject
{
    public function __construct($value)
    {
        if (!$this->validate($value)) {
            ValueObjectValidationException::throwWith($value, static::class);
        }
    }

    abstract protected function rules(): string;

    protected function validate($value) {
        return Validator::make(['value' => $value], [
            'value' => 'required|' . static::rules()
        ])->passes();
    }
}
