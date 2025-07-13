package org.example.steps.serenity;
import static org.hamcrest.Matchers.is;
import org.example.pages.CarturestiPage;
import org.example.pages.DictionaryPage;
import net.thucydides.core.annotations.Step;
import net.thucydides.core.steps.ScenarioSteps;

import static org.hamcrest.MatcherAssert.assertThat;
import static org.hamcrest.Matchers.containsString;
import static org.hamcrest.Matchers.hasItem;
import static org.junit.Assert.assertFalse;

public class EndUserSteps {

    DictionaryPage dictionaryPage;

    @Step
    public void enters(String keyword) {
        dictionaryPage.enter_keywords(keyword);
    }

    @Step
    public void starts_search() {
        dictionaryPage.lookup_terms();
    }

    @Step
    public void should_see_definition(String definition) {
        assertThat(dictionaryPage.getDefinitions(), hasItem(containsString(definition)));
    }

    @Step
    public void is_the_home_page() {
        dictionaryPage.open();
    }

    @Step
    public void looks_for(String term) {
        enters(term);
        starts_search();
    }

    CarturestiPage carturestiPage;

    @Step
    public void is_on_carturesti_home_page() {
        carturestiPage.open();
    }

    @Step
    public void searches_for(String keyword) {
        carturestiPage.enter_search_term(keyword);
        carturestiPage.submit_search();
    }

    @Step
    public void should_see_search_result(String expected) {
        assertThat(carturestiPage.getPageText(), containsString(expected));
    }
    public void should_see_abonare_result(String expected) {
//        carturestiPage.scroll_down_a_bit();
//        carturestiPage.scroll_down_a_bit();
        //assertThat(carturestiPage.getPageText(), containsString(expected));
        assertThat(carturestiPage.getAbonareSuccessText(), containsString(expected));
    }


    @Step
    public void should_see_filter_result(String expected) {
        carturestiPage.scroll_to_bottom();
        assertThat(carturestiPage.getPageText(), containsString(expected));
    }

    @Step
    public void clicks_category_button() {
        carturestiPage.click_category_button();
    }

    @Step
    public void searches_for_category(String categoryName) {
        carturestiPage.search_category(categoryName);
    }

    @Step
    public void fill_form_data(String input) {

        carturestiPage.handle_cookie_popup();

        String[] values = input.split("\\|");
        if (values.length < 3) {
            throw new IllegalArgumentException("Input must be in format: email|lastName|firstName");
        }

        carturestiPage.handle_cookie_popup();

        String email = values[0].trim();
        carturestiPage.emailField.waitUntilVisible().type(email);
        carturestiPage.lastNameField.waitUntilVisible().type(values[1].trim());
        carturestiPage.firstNameField.waitUntilVisible().type(values[2].trim());

        if (!email.contains("@")) {
//            assertThat(carturestiPage.getEmailErrorMessage(), containsString("Aceasta nu este o adresă de email validă."));
            carturestiPage.abonareButton.click();
            assertFalse(carturestiPage.getPageText().contains("Aproape am terminat"));
        } else {
            carturestiPage.abonareButton.waitUntilClickable().click();
            assertThat(carturestiPage.getAbonareSuccessText(), containsString("Aproape am terminat"));
        }
    }


}