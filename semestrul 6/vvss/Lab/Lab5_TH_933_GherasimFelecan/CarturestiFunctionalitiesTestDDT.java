package org.example.features.search;


import net.serenitybdd.junit.runners.SerenityParameterizedRunner;
import net.serenitybdd.junit.runners.SerenityRunner;
import net.thucydides.core.annotations.Managed;
import net.thucydides.core.annotations.Steps;
import net.thucydides.junit.annotations.Qualifier;
import net.thucydides.junit.annotations.UseTestDataFrom;
import org.example.steps.serenity.EndUserSteps;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.openqa.selenium.WebDriver;

@RunWith(SerenityParameterizedRunner.class)
@UseTestDataFrom("src/test/resources/CarturestiTestData.csv")
public class CarturestiFunctionalitiesTestDDT {

    @Managed(uniqueSession = true)
    public WebDriver webdriver;

    @Steps
    public EndUserSteps endUser;

    public String feature;
    public String input;
    public String expectedResult;

    @Qualifier
    public String getQualifier() {
        return feature + " - " + input;
    }

    @Test
    public void testCarturestiFunctionality() {
        webdriver.manage().window().maximize();
        endUser.is_on_carturesti_home_page();

        if (feature.equalsIgnoreCase("search")) {
            endUser.searches_for(input);
            endUser.should_see_search_result(expectedResult);
        }
//        else if (feature.equalsIgnoreCase("filter")) {
//            endUser.clicks_category_button();
//            endUser.searches_for_category(input);
//            endUser.should_see_filter_result(expectedResult);
//        }
        if (feature.equalsIgnoreCase("abonare")){
            endUser.fill_form_data(input);

            if (input.contains("@")) {
                endUser.should_see_abonare_result(expectedResult);
            }
        }
    }


    public String getFeature() {
        return feature;
    }

    public void setFeature(String feature) {
        this.feature = feature;
    }

    public String getInput() {
        return input;
    }

    public void setInput(String input) {
        this.input = input;
    }

    public String getExpectedResult() {
        return expectedResult;
    }

    public void setExpectedResult(String expectedResult) {
        this.expectedResult = expectedResult;
    }
}
