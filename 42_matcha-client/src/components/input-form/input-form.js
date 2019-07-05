import React from 'react';

const InputForm = (props) => {

    const elements = React.Children.map(props.children, child => {
        child = React.cloneElement(child, { 
            id: props.id + '-' +  child.props.name,
            onChange: () => { console.log(event) }
        });

        return child;
    })

    return (
        <form>
            {
                elements
            }
        </form>
    )
};

export default InputForm;
