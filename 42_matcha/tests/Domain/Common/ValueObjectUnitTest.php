<?php

namespace Domain\Common;

use Domain\Common\Exceptions\ValueObjectValidationException;
use TestCase;

class ValueObjectUnitTest extends TestCase
{
    public function testValueObjectCreationWithInvalidValue()
    {
        $this->expectException(ValueObjectValidationException::class);

        $this->createValueObject(42, 'string');
    }

    public function testValueObjectCreationWithValidValue()
    {
        $this->createValueObject('stringValue', 'string');

        $this->addToAssertionCount(1);
    }

    private function createValueObject($value, string $rules) {

        return new class($value, $rules) extends ValueObject {

            private string $rules;

            public function __construct($value, $rules)
            {
                $this->rules = $rules;

                parent::__construct($value);
            }

            protected function rules(): string {
                return $this->rules;
            }
        };
    }
}
