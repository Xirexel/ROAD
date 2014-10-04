#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <mutex>



namespace FractalDecoding
{

	class LogPrintOut
	{
	public:

		enum Level
		{
			INFO_LEVEL=1,
			ERROR_LEVEL=2
		};
				
		static LogPrintOut& getInstance()
		{
			static LogPrintOut instance;

			return instance;
		}

		void setVerbose(bool state)
		{
			std::lock_guard<std::mutex> lock(mLogPrintOutMutex);

			mVerbose = state;
		}

		bool setPtrLogPrintOutStream(Level level, std::wostream* pwostream, bool selfReleased)
		{
			std::lock_guard<std::mutex> lock(mLogPrintOutMutex);

			bool result = false;

			if (pwostream == nullptr)
				return result;

			releaseStream(level);

			Stream stream;

			stream.pwostream = pwostream;

			stream.selfReleased = selfReleased;

			mLevelStreams[level] = stream;

			result = true;

			return result;
		}

		bool releaseLogPrintOutStream(Level level)
		{
			std::lock_guard<std::mutex> lock(mLogPrintOutMutex);

			return releaseStream(level);
		}

		template<typename T>
		inline bool printOutln(Level level, const T *data)
		{
			std::lock_guard<std::mutex> lock(mLogPrintOutMutex);

			bool result = false;

			if (mVerbose)
			{

				auto itr = mLevelStreams.find(level);

				if (itr == mLevelStreams.end())
					return result;

				if (itr->second.pwostream == nullptr)
					return result;

				switch (level)
				{
                case LogPrintOut::INFO_LEVEL:
					(*(itr->second.pwostream)) << L"INFO_LEVEL: ";
					break;
                case LogPrintOut::ERROR_LEVEL:
					(*(itr->second.pwostream)) << L"ERROR_LEVEL: ";
					break;
				default:
					break;
				}

				(*(itr->second.pwostream))<<(data) << std::endl;

				itr->second.pwostream->flush();

				result = true;

			}

			return result;
		}

		template<typename T>
		inline bool printOutln(Level level, const T data)
		{
			std::lock_guard<std::mutex> lock(mLogPrintOutMutex);

			bool result = false;

			if (mVerbose)
			{

				auto itr = mLevelStreams.find(level);

				if (itr == mLevelStreams.end())
					return result;

				if (itr->second.pwostream == nullptr)
					return result;

				switch (level)
				{
                case LogPrintOut::INFO_LEVEL:
					(*(itr->second.pwostream)) << L"INFO_LEVEL: ";
					break;
                case LogPrintOut::ERROR_LEVEL:
					(*(itr->second.pwostream)) << L"ERROR_LEVEL: ";
					break;
				default:
					break;
				}

				(*(itr->second.pwostream)) << (data) << std::endl;

				itr->second.pwostream->flush();

				result = true;

			}

			return result;
		}

		template <typename T, typename... Args>
		inline bool printOutln(Level level, const T data, const Args... rest)
		{
			std::lock_guard<std::mutex> lock(mLogPrintOutMutex);

			bool result = false;

			if (mVerbose)
			{

				auto itr = mLevelStreams.find(level);

				if (itr == mLevelStreams.end())
					return result;

				if (itr->second.pwostream == nullptr)
					return result;

				switch (level)
				{
                case LogPrintOut::INFO_LEVEL:
					(*(itr->second.pwostream)) << L"INFO_LEVEL: ";
					break;
                case LogPrintOut::ERROR_LEVEL:
					(*(itr->second.pwostream)) << L"ERROR_LEVEL: ";
					break;
				default:
					break;
				}

				write(itr->second.pwostream, data, rest...);

				itr->second.pwostream->operator<<(std::endl);

				itr->second.pwostream->flush();

				result = true;
			}

			return result;
		}
		
		template <typename T, typename... Args>
		inline bool printOutln(Level level, const T *data, const Args... rest)
		{
			std::lock_guard<std::mutex> lock(mLogPrintOutMutex);

			bool result = false;

			if (mVerbose)
			{

				auto itr = mLevelStreams.find(level);

				if (itr == mLevelStreams.end())
					return result;

				if (itr->second.pwostream == nullptr)
					return result;

				switch (level)
				{
                case LogPrintOut::INFO_LEVEL:
					(*(itr->second.pwostream)) << L"INFO_LEVEL: ";
					break;
                case LogPrintOut::ERROR_LEVEL:
					(*(itr->second.pwostream)) << L"ERROR_LEVEL: ";
					break;
				default:
					break;
				}

				write(itr->second.pwostream, data, rest...);

				itr->second.pwostream->operator<<(std::endl);

				itr->second.pwostream->flush();

				result = true;
			}

			return result;
		}

		template<typename T>
		inline bool printOut(Level level, const T *data)
		{
			std::lock_guard<std::mutex> lock(mLogPrintOutMutex);

			bool result = false;

			if (mVerbose)
			{

				auto itr = mLevelStreams.find(level);

				if (itr == mLevelStreams.end())
					return result;

				if (itr->second.pwostream == nullptr)
					return result;

				switch (level)
				{
                case LogPrintOut::INFO_LEVEL:
					(*(itr->second.pwostream)) << L"INFO_LEVEL: ";
					break;
                case LogPrintOut::ERROR_LEVEL:
					(*(itr->second.pwostream)) << L"ERROR_LEVEL: ";
					break;
				default:
					break;
				}

				(*(itr->second.pwostream)) << (data);

				itr->second.pwostream->flush();

				result = true;

			}

			return result;
		}

		template<typename T>
		inline bool printOut(Level level, const T data)
		{
			std::lock_guard<std::mutex> lock(mLogPrintOutMutex);

			bool result = false;

			if (mVerbose)
			{

				auto itr = mLevelStreams.find(level);

				if (itr == mLevelStreams.end())
					return result;

				if (itr->second.pwostream == nullptr)
					return result;

				switch (level)
				{
                case LogPrintOut::INFO_LEVEL:
					(*(itr->second.pwostream)) << L"INFO_LEVEL: ";
					break;
                case LogPrintOut::ERROR_LEVEL:
					(*(itr->second.pwostream)) << L"ERROR_LEVEL: ";
					break;
				default:
					break;
				}

				(*(itr->second.pwostream)) << (data);

				itr->second.pwostream->flush();

				result = true;

			}

			return result;
		}

		template <typename T, typename... Args>
		inline bool printOut(Level level, const T data, const Args... rest)
		{
			std::lock_guard<std::mutex> lock(mLogPrintOutMutex);

			bool result = false;

			if (mVerbose)
			{

				auto itr = mLevelStreams.find(level);

				if (itr == mLevelStreams.end())
					return result;

				if (itr->second.pwostream == nullptr)
					return result;

				switch (level)
				{
                case LogPrintOut::INFO_LEVEL:
					(*(itr->second.pwostream)) << L"INFO_LEVEL: ";
					break;
                case LogPrintOut::ERROR_LEVEL:
					(*(itr->second.pwostream)) << L"ERROR_LEVEL: ";
					break;
				default:
					break;
				}

				write(itr->second.pwostream, data, rest...);

				itr->second.pwostream->flush();

				result = true;
			}

			return result;
		}

		template <typename T, typename... Args>
		inline bool printOut(Level level, const T *data, const Args... rest)
		{
			std::lock_guard<std::mutex> lock(mLogPrintOutMutex);

			bool result = false;

			if (mVerbose)
			{

				auto itr = mLevelStreams.find(level);

				if (itr == mLevelStreams.end())
					return result;

				if (itr->second.pwostream == nullptr)
					return result;

				switch (level)
				{
                case LogPrintOut::INFO_LEVEL:
					(*(itr->second.pwostream)) << L"INFO_LEVEL: ";
					break;
                case LogPrintOut::ERROR_LEVEL:
					(*(itr->second.pwostream)) << L"ERROR_LEVEL: ";
					break;
				default:
					break;
				}

				write(itr->second.pwostream, data, rest...);

				itr->second.pwostream->flush();

				result = true;
			}

			return result;
		}
		
	private:

		struct Stream
		{
			std::wostream* pwostream = nullptr;

			bool selfReleased = false;
		};

		std::map<Level, Stream> mLevelStreams;

		bool mVerbose = true;

		std::mutex mLogPrintOutMutex;

		LogPrintOut()
		{

            this->setPtrLogPrintOutStream(INFO_LEVEL, new std::wofstream("C:\\Users\\Logan\\Documents\\decodeResult.txt"), true);

//			setPtrLogPrintOutStream(LogPrintOut::INFO_LEVEL, &std::wcout, false);

//			setPtrLogPrintOutStream(LogPrintOut::ERROR_LEVEL, &std::wcout, false);
		}

		~LogPrintOut()
		{
			std::lock_guard<std::mutex> lock(mLogPrintOutMutex);

			releaseStreams();
		}


		LogPrintOut(const LogPrintOut&);

		LogPrintOut& operator=(const LogPrintOut&);

		void releaseStreams()
		{
			auto itr = mLevelStreams.begin();

			for (; itr != mLevelStreams.end(); ++itr)
			{
				if (itr->second.selfReleased && itr->second.pwostream != nullptr)
				{
					itr->second.pwostream->flush();

					delete itr->second.pwostream;
				}
			}

			mLevelStreams.clear();
		}

		bool releaseStream(Level level)
		{

			bool result = false;

			auto itr = mLevelStreams.find(level);

			if (itr != mLevelStreams.end())
			{
				if (itr->second.selfReleased && itr->second.pwostream != nullptr)
				{
					itr->second.pwostream->flush();
					
					delete itr->second.pwostream;

					mLevelStreams.erase(itr);

					result = true;
				}
			}

			return result;

		}

		template <typename T>
		inline void write(std::wostream* pwostream, const T *data)
		{
			(*pwostream) << (data);
		}

		template <typename T>
		inline void write(std::wostream* pwostream, const T data)
		{
			(*pwostream) << (data);
		}

		template <typename T, typename... Args>
		inline void write(std::wostream* pwostream, const T *data, const Args... rest)
		{
			(*pwostream) << (data);

			write(pwostream, rest...);
		}

		template <typename T, typename... Args>
		inline void write(std::wostream* pwostream, const T data, const Args... rest)
		{
			(*pwostream) << (data);

			write(pwostream, rest...);
		}

	};

}
