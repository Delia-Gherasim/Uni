
import org.example.PaymentProcessorVersionB;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class PaymentProcessorTest {

    PaymentProcessorVersionB processor = new PaymentProcessorVersionB();
    PaymentProcessorVersionB.PaymentMethod CreditMethod = PaymentProcessorVersionB.PaymentMethod.CREDIT_CARD;
    PaymentProcessorVersionB.PaymentMethod PaypalMethod = PaymentProcessorVersionB.PaymentMethod.PAYPAL;
    PaymentProcessorVersionB.PaymentMethod CashMethod = PaymentProcessorVersionB.PaymentMethod.CASH;

    @Test
    void testCreditCardFirstOrder() {
        double result = processor.processPayment(100.0, true, CreditMethod);
        double discounted = 100.0 * (1 - 0.15);
        double expected = Math.round(discounted * 1.15 * 100.0) / 100.0;
        assertEquals(expected, result);
    }

    @Test
    void testCreditCardNonFirstOrder() {
        double result = processor.processPayment(100.0, false, CreditMethod);
        double discounted = 100.0 * (1 - 0.05);
        double expected = Math.round(discounted * 1.15 * 100.0) / 100.0;
        assertEquals(expected, result);
    }

    @Test
    void testPaypalFirstOrder() {
        double result = processor.processPayment(100.0, true, PaypalMethod);
        double discounted = 100.0 * (1 - 0.12);
        double expected = Math.round(discounted * 1.15 * 100.0) / 100.0;
        assertEquals(expected, result);
    }

    @Test
    void testPaypalNonFirstOrder() {
        double result = processor.processPayment(100.0, false, PaypalMethod);
        double discounted = 100.0 * (1 - 0.02);
        double expected = Math.round(discounted * 1.15 * 100.0) / 100.0;
        assertEquals(expected, result);
    }

    @Test
    void testCashFirstOrder() {
        double result = processor.processPayment(100.0, true, CashMethod);
        double discounted = 100.0 * (1 - 0.10);
        double expected = Math.round(discounted * 1.15 * 100.0) / 100.0;
        assertEquals(expected, result);
    }

    @Test
    void testCashNonFirstOrder() {
        double result = processor.processPayment(100.0, false, CashMethod);
        double discounted = 100.0;
        double expected = Math.round(discounted * 1.15 * 100.0) / 100.0;
        assertEquals(expected, result);
    }

    @Test
    void testNegativeAmountThrowsException() {
        assertThrows(IllegalArgumentException.class, () -> {
            processor.processPayment(-50.0, true, CreditMethod);
        });
    }

    @Test
    void testZeroAmountThrowsException() {
        assertThrows(IllegalArgumentException.class, () -> {
            processor.processPayment(0.0, false, PaypalMethod);
        });
    }

    @Test
    void testDeliveryFeeBelowThreshold() {
        assertEquals(5.0, processor.calculateDeliveryFee(49.99));
    }

    @Test
    void testDeliveryFeeAtThreshold() {
        assertEquals(0.0, processor.calculateDeliveryFee(50.0));
    }

    @Test
    void testDeliveryFeeAboveThreshold() {
        assertEquals(0.0, processor.calculateDeliveryFee(99.99));
    }
}
