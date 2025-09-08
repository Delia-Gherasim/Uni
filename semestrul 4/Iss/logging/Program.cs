namespace logging
{
    internal class Program
    {
        static void Main(string[] args)
        {
            LoggingModule logger = new LoggingModule();

            logger.Log(SeverityLevels.INFO, "This is an info message.");
            logger.Log(SeverityLevels.DEBUG, "This is a debug message.");
            logger.Log(SeverityLevels.WARNING, "This is a warning message.");
            logger.Log(SeverityLevels.ERROR, "This is an error message.");
            logger.Log(SeverityLevels.FATAL, "This is a fatal message.");

            logger = new LoggingModule(
                "INFO: Multiple info messages.",
                "DEBUG: Multiple debug messages.",
                "WARNING: Multiple warning messages.",
                "ERROR: Multiple error messages.",
                "FATAL: Multiple fatal messages."
            );

            logger.Log(SeverityLevels.INFO, "Buffered message 1.");
            logger.Log(SeverityLevels.INFO, "Buffered message 2.");
            logger.Log(SeverityLevels.INFO, "Buffered message 3.");
            logger.Log(SeverityLevels.INFO, "Buffered message 4.");
            logger.Log(SeverityLevels.INFO, "Buffered message 5.");

            logger.Log(SeverityLevels.ERROR, "This is an error message.");

            Console.WriteLine("Test cases executed. Check log files for output.");
        }
    }
}