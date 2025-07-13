package org.example.pages;

import net.thucydides.core.annotations.DefaultUrl;
import net.serenitybdd.core.pages.PageObject;
import net.serenitybdd.core.pages.WebElementFacade;
import org.openqa.selenium.*;
import net.serenitybdd.core.annotations.findby.FindBy;

import java.util.List;

@DefaultUrl("https://carturesti.ro")
public class CarturestiPage extends PageObject {

    @FindBy(id = "search-input")
    private WebElementFacade searchInput;

    @FindBy(css = "button[type='submit']")
    private WebElementFacade searchButton;

    @FindBy(xpath = "//*[@id=\"buton-produse\"]/i")
    private WebElementFacade produseButton;

    @FindBy(css = "button.js-cookie-consent-agree")
    private List<WebElementFacade> cookieConsentButtons;

    @FindBy(id = "subscriptionform-email")
    public WebElementFacade emailField;

    @FindBy(id = "subscriptionform-last_name")
    public WebElementFacade lastNameField;

    @FindBy(id = "subscriptionform-first_name")
    public WebElementFacade firstNameField;

    @FindBy(xpath = "//input[@type='submit' and @value='Abonare']")
    public WebElementFacade abonareButton;

    @FindBy(css = "div#w1-success.alert-success")
    private WebElementFacade abonareSuccessAlert;

    @FindBy(css = "div.help-block")
    private WebElementFacade emailErrorMessage;

    public void enter_search_term(String term) {
        waitForPageToLoad();
        handle_cookie_popup();
        searchInput.waitUntilVisible().type(term);
    }

    public void submit_search() {
        waitForPageToLoad();
        handle_cookie_popup();
        searchInput.sendKeys(Keys.ENTER);
    }

    public void click_produse() {
        waitForPageToLoad();
        handle_cookie_popup();
        produseButton.waitUntilClickable().click();
    }

    public void click_category(String categoryName) {
        WebElementFacade category = find(By.partialLinkText(categoryName));
        category.waitUntilVisible().waitUntilClickable().click();
    }
    public void click_category_button() {
        //WebElementFacade categoryButton = find(By.cssSelector("body > div.content-wrap.logged-out.site-cartu > div.cartu-top-bar.md-whiteframe-z1.clean-a"));
        WebElementFacade categoryButton = find(By.partialLinkText("PRODUSE"));
        categoryButton.waitUntilClickable().click();
    }

    public void search_category(String categoryName) {
        WebElementFacade category = find(By.partialLinkText(categoryName));  // Finding the category by partial link text
        category.waitUntilClickable().click();  // Click the category
    }


    public void scroll_to_bottom() {
        JavascriptExecutor js = (JavascriptExecutor) getDriver();
        long lastHeight = (long) js.executeScript("return document.body.scrollHeight");

        while (true) {
            js.executeScript("window.scrollTo(0, document.body.scrollHeight);");
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                break;
            }
            long newHeight = (long) js.executeScript("return document.body.scrollHeight");
            if (newHeight == lastHeight) break;
            lastHeight = newHeight;
        }
    }

    public void scroll_down_a_bit() {
        JavascriptExecutor js = (JavascriptExecutor) getDriver();
        js.executeScript("window.scrollBy(0, 300);"); // Scroll down by 300 pixels
    }

    public String getPageText() {
        return getDriver().findElement(By.tagName("body")).getText();
    }
    public String getAbonareSuccessText() {
        return abonareSuccessAlert.waitUntilVisible().getText();
    }

    public void handle_cookie_popup() {
        if (!cookieConsentButtons.isEmpty()) {
            cookieConsentButtons.get(0).click();
        }
    }

    private void waitForPageToLoad() {
        JavascriptExecutor js = (JavascriptExecutor) getDriver();
        waitForCondition().until(driver ->
                js.executeScript("return document.readyState").equals("complete")
        );
    }

    public void fill_form(String input) {
        scroll_to_bottom();
        String[] values = input.split("\\|");
        if (values.length < 3) {
            throw new IllegalArgumentException("Input must be in format: email|lastName|firstName");
        }

        handle_cookie_popup();

        emailField.waitUntilVisible().type(values[0].trim());
        lastNameField.waitUntilVisible().type(values[1].trim());
        firstNameField.waitUntilVisible().type(values[2].trim());

        abonareButton.waitUntilClickable().click();
    }

    public String getEmailErrorMessage() {
        return emailErrorMessage.waitUntilVisible().getText();
    }

}
