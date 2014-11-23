#include <QString>
#include <QtTest>

#include "EndianConvertor.h"

class TestEndianTest : public QObject
{
    Q_OBJECT

public:
    TestEndianTest();

private Q_SLOTS:
    void testCase1();
};

TestEndianTest::TestEndianTest()
{
}

void TestEndianTest::testCase1()
{
    unsigned int j = 1;
    unsigned char* t = (unsigned char*)&j;

    unsigned int h = Endian::EndianConvertor::getInstance().convertToUINT32(t);

    QVERIFY2(h != 1, "Failure");
}

QTEST_APPLESS_MAIN(TestEndianTest)

#include "tst_testendiantest.moc"
