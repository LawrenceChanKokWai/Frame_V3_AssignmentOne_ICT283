
#include<iostream>
#include<iomanip>

#include "Vector.h"

using namespace std;

void TestVectorIsEmpty( const Vector<unsigned> &testVector, const float &testId );
void TestDefaultVectorConstructor( const Vector<unsigned> &testVector, const float &testId );
void TestInsertObjectIntoVector( Vector<unsigned> &testVector, const unsigned &object, const float &testId );
void TestCheckElementUsingStartFinishPtr( Vector<unsigned> &testVector, const float &testId );
void TestCopyConstructor( Vector<unsigned> &testVector, const float &testId );
void TestEqualOperator( Vector<unsigned> &testVector, const float &testId );
void TestDeleteObject( Vector<unsigned> &testVector, const float &testId );

int main()
{
    Vector<unsigned> myVec;

    TestVectorIsEmpty( myVec, 1.0 );
    TestDefaultVectorConstructor( myVec, 2.0 );
    TestInsertObjectIntoVector( myVec, 10, 3.0 );
    TestInsertObjectIntoVector( myVec, 20, 3.1 );
    TestCheckElementUsingStartFinishPtr( myVec, 4.0 );
    TestCopyConstructor( myVec, 5.0 );
    TestEqualOperator( myVec, 6.0 );
    TestDeleteObject( myVec, 7.0 );

    return 0;
}

void Assert( bool condition, const string &message )
{
    if( condition )
    {
        cout << setw(5) << " " << "[ PASS ] " << message << endl;
    }
    else
    {
        cout << setw(5) << " " <<  "[ FAIL ] " << message << endl;
    }
}

void TestVectorIsEmpty( const Vector<unsigned> &testVector, const float &testId )
{
    cout << "V"  <<  testId << ": Test Vector Is Empty --> " << endl;
    Assert( testVector.IsEmpty(), "Vector Is Empty" );
    cout << setw(5) << " " << "Actual Used: " << testVector.GetUsed() << endl;
}

void TestDefaultVectorConstructor( const Vector<unsigned> &testVector, const float &testId )
{
    cout << "V" << testId << ": Test default constructed Vector Object --> " << endl;
    Assert( testVector.GetCapacity() == 2, "Set Capacity to Default Constructed Vector" );
    Assert( testVector.GetUsed() == 0, "Set Used Slot to Default Constructed Vector" );
    cout << setw(5) << " " << "Actual Capacity: " << testVector.GetCapacity() << ", Actual Used: " << testVector.GetUsed() << endl;
}

void TestInsertObjectIntoVector( Vector<unsigned> &testVector, const unsigned &object, const float &testId )
{
    cout << "V" << testId << ": Test Inserting Object into Vector Object --> " << endl;
    Assert( testVector.InsertObject( object ), "Inserted Object into Vector" );
    cout << setw(5) << " " << "Actual Capacity: " << testVector.GetCapacity() << ", Actual Used: " << testVector.GetUsed() << endl;
    cout << setw(5) << " " << "Actual Addresses of Element: ";
    for( unsigned *ptr = testVector.Start(); ptr != testVector.Finish(); ptr++ )
    {
        cout << ptr << " ";
    }
    cout << endl;
}

void TestCheckElementUsingStartFinishPtr( Vector<unsigned> &testVector, const float &testId )
{
    cout << "V" << testId << ": Test Start & Finish Pointer --> " << endl;
    cout << setw(5) << " " << "Actual Elements in Vector: ";
    for( unsigned *ptr = testVector.Start(); ptr != testVector.Finish(); ptr++ )
    {
        cout << *ptr << " ";
    }
    cout << endl;
}

void TestCopyConstructor( Vector<unsigned> &testVector, const float &testId )
{
    Vector<unsigned> copyVec( testVector );
    cout << "V" << testId << ": Test Copy Constructor / Addresses of both vector & element to be different --> " << endl;
    cout << setw(5) << " " << "Actual Elements in OtherVector: " << endl;
    unsigned otherCount = 0;
    unsigned thisCount = 0;
    unsigned *ptr;
    for( ptr = testVector.Start(); ptr != testVector.Finish(); ptr++ )
    {
        cout << setw(5) << " " << "otherVector [ " << otherCount << " ]: " << *ptr << " " << ptr << endl;
        otherCount ++;
    }
    delete ptr;
    ptr = nullptr;
    cout << "-------------------------------------------------------------------------------" << endl;
    for( ptr = copyVec.Start(); ptr != copyVec.Finish(); ptr++ )
    {
        cout << setw(5) << " " << "thisVector [ " << thisCount << " ]: " << *ptr << " " << ptr << endl;
        thisCount ++;
    }
    cout << endl;
}

void TestEqualOperator( Vector<unsigned> &testVector, const float &testId )
{
    Vector<unsigned> equalVec = testVector;
    cout << "V" << testId << ": Test Copy Constructor / Addresses of both vector & element to be different --> " << endl;
    cout << setw(5) << " " << "Actual Elements in OtherVector: " << endl;
    unsigned otherCount = 0;
    unsigned thisCount = 0;
    unsigned *ptr;
    for( ptr = testVector.Start(); ptr != testVector.Finish(); ptr++ )
    {
        cout << setw(5) << " " << "otherVector [ " << otherCount << " ]: " << *ptr << " " << ptr << endl;
        otherCount ++;
    }
    delete ptr;
    ptr = nullptr;
    cout << "-------------------------------------------------------------------------------" << endl;
    for( ptr = equalVec.Start(); ptr != equalVec.Finish(); ptr++ )
    {
        cout << setw(5) << " " << "thisVector [ " << thisCount << " ]: " << *ptr << " " << ptr << endl;
        thisCount ++;
    }
    cout << endl;
}

void TestDeleteObject( Vector<unsigned> &testVector, const float &testId )
{
    cout << "V" << testId << ": Test Delete Object / Addresses of both vector & element to be different --> " << endl;
    cout << setw(5) << " " << "Actual Elements in OtherVector: " << endl;
    unsigned otherCount = 0;
    unsigned *ptr;
    Assert( testVector.DeleteObject(), "Delete Object from Vector" );
    for( ptr = testVector.Start(); ptr != testVector.Finish(); ptr++ )
    {
        cout << setw(5) << " " << "otherVector [ " << otherCount << " ]: " << *ptr << " " << ptr << endl;
        otherCount ++;
    }
    cout << endl;
}
