<?php

namespace Domain\User\ValueObjects;

use Domain\Common\ValueObject;

class Username extends ValueObject
{
    protected function rules(): string
    {
        return 'string';
    }
}
