#include "stream.h"
#include "zlib/zlib.h"

namespace utils
{
    //��ͷ�����"ZiPeDit"ѹ��ͷ��Ԥ��ѹ��ͷ�ֽڳ��ȿռ䣬��zlibѹ������ʼ��ַ��ΪԤ������
    static const string zipString = "ZiPeDit";
    static const string::size_type zipLen = zipString.length();
    bool zlibCompress(const ByteArray& srcData, ByteArray& dstData)
    {
        bool ok = false;
        unsigned long reserveBytes = zipLen;
        unsigned long srcDataLen = srcData.size();
        unsigned long dstDataLen = srcDataLen * 2;

        if (srcDataLen <= 0)
        {
            return false;
        }

        dstData.resize(dstDataLen + reserveBytes);
        r_int32 ret = compress(&dstData[reserveBytes], &dstDataLen, &srcData[0], srcDataLen);
        switch (ret)
        {
        case Z_OK:
            ok = true;
            dstData.resize(dstDataLen + reserveBytes);
            //ѹ���ɹ�������ѹ��ͷ
            memcpy(&dstData[0], zipString.c_str(), reserveBytes);
            break;
        default:
            //ѹ��ʧ�ܣ�������ѹ��ͷ������ԭʼ����
            dstData.resize(srcDataLen);
            memcpy(&dstData[0], &srcData, srcDataLen);
            break;
        }

        return ok;
    }

    bool zlibDecompress(const ByteArray& srcData, ByteArray& dstData)
    {
        bool ok = false;
        bool stop = false;

        unsigned long reserveBytes = zipLen;
        unsigned long srcDataLen = srcData.size();
        unsigned long dstDataLen = srcDataLen * 10;

        if (srcDataLen <= 0)
        {
            return ok;
        }

        dstData.resize(dstDataLen);
        if ((srcDataLen < reserveBytes) || (strncmp((const char*)&srcData[0], zipString.c_str(), zipLen) != 0))
        {
            dstData.resize(srcDataLen);
            memcpy(&dstData[0], &srcData[0], srcDataLen);
            ok = true;
            return ok;
        }

        while (true)
        {
            r_int32 ret = uncompress(&dstData[0], &dstDataLen, &srcData[reserveBytes], srcDataLen - reserveBytes);
            switch (ret)
            {
            case Z_OK:
                {
                    ok = true;
                    stop = true;
                    dstData.resize(dstDataLen);
                }
                break;
            case Z_BUF_ERROR:
                {
                    dstDataLen += dstDataLen;
                    dstData.resize(dstDataLen);
                }
                break;
            default:
                {
                    stop = true;
                }
                break;
            }

            if (stop)
            {
                break;
            }
        }

        if (!ok)
        {
            //��ѹʧ�ܣ�����ԭʼ����
            dstData.resize(srcDataLen - reserveBytes);
            memcpy(&dstData[0], &srcData[reserveBytes], srcDataLen - reserveBytes);
        }
        return ok;
    }
}