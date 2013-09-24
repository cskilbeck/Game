//////////////////////////////////////////////////////////////////////

#pragma once

//////////////////////////////////////////////////////////////////////

class File
{
public:

	//////////////////////////////////////////////////////////////////////

	enum AccessMode
	{
		AccessRead,
		AccessWrite,
		AccessAppend
	};

	//////////////////////////////////////////////////////////////////////

	File(TCHAR const *name, AccessMode AccessMode)
	{
		TCHAR const *access = null;
		switch(AccessMode)
		{
			case AccessRead:
				access = TEXT("rb");
				break;

			case AccessWrite:
				access = TEXT("wb");
				break;

			case AccessAppend:
				access = TEXT("ab");
				break;
		}
		if(access != null)
		{
			int error = _wfopen_s(&mHandle, name, access);
			if(error != 0)
			{
				MessageBox(null, Format(TEXT("Error %d opening file %s (%s)"), error, name, access).c_str(), TEXT("File Error"), MB_ICONEXCLAMATION);
			}
		}
	}

	//////////////////////////////////////////////////////////////////////

	bool IsValid() const
	{
		return mHandle != null;
	}

	//////////////////////////////////////////////////////////////////////

	long Size()
	{
		long len = 0;
		if(IsValid())
		{
			fseek(mHandle, 0, SEEK_END);
			len = ftell(mHandle);
			fseek(mHandle, 0, SEEK_SET);
		}
		return len;
	}

	//////////////////////////////////////////////////////////////////////

	long Position()
	{
		if(IsValid())
		{
			return ftell(mHandle);
		}
		else
		{
			return 0;
		}
	}

	//////////////////////////////////////////////////////////////////////

	void Seek(long offset)
	{
		if(IsValid())
		{
			fseek(mHandle, (long)offset, SEEK_SET);
		}
	}

	//////////////////////////////////////////////////////////////////////

	long Read(void *p, long s)
	{
		if(IsValid())
		{
			return fread_s(p, s, sizeof(byte), s, mHandle);
		}
		else
		{
			return 0;
		}
	}

	//////////////////////////////////////////////////////////////////////

	long Write(void const *p, long s)
	{
		if(IsValid())
		{
			return fwrite(p, s, sizeof(byte), mHandle);
		}
		else
		{
			return 0;
		}
	}

	//////////////////////////////////////////////////////////////////////

	~File()
	{
		if(IsValid())
		{
			fclose(mHandle);
			mHandle = null;
		}
	}

	//////////////////////////////////////////////////////////////////////

private:

	FILE *mHandle;
};
