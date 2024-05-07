using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;

namespace logging
{
    public enum SeverityLevels
    {
        FATAL,
        ERROR,
        WARNING,
        INFO,
        DEBUG,
        TRACE
    }

    public class LoggingModule
    {
        private string filePath;
        private Queue<string> bufferedMessages;
        private const int BufferSize = 3; 
        private object bufferLock = new object();

        public LoggingModule()
        {
            this.filePath = CreateFile();
            this.bufferedMessages = new Queue<string>();
        }

        public LoggingModule(SeverityLevels receivedLevel, string receivedMessage)
        {
            this.filePath = CreateFile();
            this.bufferedMessages = new Queue<string>();
            Log(receivedLevel, receivedMessage);
        }

        public LoggingModule(params string[] messages)
        {
            this.filePath = CreateFile();
            this.bufferedMessages = new Queue<string>();
            foreach (string message in messages)
            {
                foreach (SeverityLevels possibleLevel in Enum.GetValues(typeof(SeverityLevels)))
                {
                    if (message.Contains(possibleLevel.ToString()))
                    {
                        Log(possibleLevel, message.Replace(possibleLevel.ToString(), "").Trim());
                        break;
                    }
                }
            }
        }

        private string CreateFile()
        {
            string fileName = "LoggingFile" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".txt";
            string fullPath = Path.Combine(Environment.CurrentDirectory, fileName);
            Console.WriteLine(fullPath);
            return fullPath;
        }

        public void Log(SeverityLevels level, string message)
        {
            lock (bufferLock)
            {
                if (level == SeverityLevels.FATAL || level == SeverityLevels.ERROR || level == SeverityLevels.WARNING)
                {
                    WriteToFile(level.ToString(), message);
                }
                else
                {
                    bufferedMessages.Enqueue($"{level.ToString()}: {message}");
                    if (bufferedMessages.Count >= BufferSize )
                    {
                        FlushBufferedMessages();
                    }
                }
            }
        }

        private void FlushBufferedMessages()
        {
            lock (bufferLock)
            {
                using (StreamWriter outputFile = new StreamWriter(this.filePath, true))
                {
                    while (bufferedMessages.Count > 0)
                    {
                        string bufferedMessage = bufferedMessages.Dequeue();
                        outputFile.WriteLine(bufferedMessage);
                        outputFile.WriteLine(DateTime.Now.ToString());
                        outputFile.WriteLine();
                        outputFile.WriteLine();
                    }
                }
            }
        }

        private void WriteToFile(string severity, string logMessage)
        {
            using (StreamWriter outputFile = new StreamWriter(this.filePath, true))
            {
                outputFile.WriteLine(severity);
                outputFile.WriteLine(logMessage);
                outputFile.WriteLine(DateTime.Now.ToString());
                outputFile.WriteLine();
                outputFile.WriteLine();
            }
        }
    }
}
