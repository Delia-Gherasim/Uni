import {render} from '@testing-library/react';
import {BrowserRouter as Router} from 'react-router-dom';
import {describe, expect, it} from 'vitest';
import Home from './Home';

describe('Home', () => {
    it('should render the Home component', () => {
        const renderedComp = render(
            <Router>
                <Home />
            </Router>,
        );
        expect(renderedComp).toMatchSnapshot();
    });
});
