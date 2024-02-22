#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

/** < Vector Class
* @brief Defines a Vector Class, Dynamic Array Implementation
*
* This class provides basic functionality for a dynamic array,
* it includes appending objects, accessing object by providing index,
* resizing of the dynamic array.
*
* @tparam  T Type
*
* @version 1.0.0
*/
template<class T>
class Vector
{
public:

    /**
    * @name Constructor and Destructor
    * @{
    */

    /**
    * @brief Default constructor.
    *
    * Initializes the vector with an initial capacity to two,
    * sets the number of used elements to zero,
    * and creates a new dynamic array on the heap memory with
    * initial capacity of two.
    */
    Vector();

    /**
    * @brief Destructor.
    *
    * Frees the dynamically allocated memory for the vector
    * by calling the Deallocate Method,
    * Sets the capacity back to zero,
    * Sets the number of used elements back to zero.
    */
    ~Vector();

    /** @brief Copy constructor.
    *
    * Creates a new vector as a copy of another vector
    * by calling CopyVector() method.
    *
    * @param[in] otherVector The vector to be copied from.
    * @param[out] A newly constructed vector with context copied over.
    */
    Vector( const Vector &otherVector );

    /**
    * @brief Assignment operator.
    *
    * Assigns the contents of another vector to this vector,
    * Checks if this Vector is the same as the otherVector and
    * calls the CopyVector method. Finally return *this.
    *
    * @param[in] otherVector The vector to be assigned.
    * @param[out] A newly constructed vector with context copied over.
    * @return The newly created Vector Object.
    */
    Vector &operator = ( const Vector &otherVector );

    /** @} */

    /**
    * @name Accessors
    * @{
    */

    /**
    * @brief Get the current capacity of the vector.
    *
    * @return The current capacity of the vector.
    */
    unsigned GetCapacity() const;

    /**
    * @brief Get the number of elements used in the vector.
    *
    * @return The number of used elements in the vector.
    */
    unsigned GetUsed() const;

    /**
    * @brief Check on if Vector is empty.
    *
    * @return true if vector is empty, else not empty.
    */
    bool IsEmpty() const;

    /** @} */

    /**
    * @name Element Accessors
    * @{
    */

    /**
    * @brief Access an element by vector's index.
    *
    * @param[in] index The index of the element to access in the vector.
    * @param[out] The element content from the vector index.
    * @return unsigned element object.
    */
    const T &operator [] ( const unsigned &index ) const;

    /**
    * @brief Access an element by vector's index.
    *
    * @param[in] index The index of the element to access in the vector.
    * @param[out] The element content from the vector index.
    * @return unsigned element object.
    */
    T &operator [] ( const unsigned &index );

    /**
    * @brief Pointer that points on the start of the vector index[0].
    *
    * @return The vector index [0].
    */
    T *Start();

    /**
    * @brief Pointer that points on the end of the vector index.
    *
    * @return The end of the vector index.
    */
    T *Finish();

    /** @} */

    /**
    * @name Modifiers
    * @{
    */

    /**
    * @brief Insert an object to the end of the vector.
    *
    * If the vector's number of elements is half of the vector's capacity,
    * it will be resized to double its capacity by calling the Resize() method.
    *
    * @param[in] object The object to be inserted to the vector end.
    * @param[out] True if the operation was successful, false otherwise.
    * @return boolean data type.
    */
    bool InsertObject( const T &object );

    /**
    * @brief Removes an object on the end index of the vector.
    *
    * Removes the object from the end index in the vector.
    *
    * @param[out] True if the operation was successful, false otherwise.
    * @return boolean data type.
    */
    bool DeleteObject();

    /** @} */

private:
    unsigned INITIAL_CAPACITY = 2;    ///< Represents the vector's initial capacity
    unsigned INITIAL_VALUE = 0;         ///< Represents the default initial value

    unsigned m_capacity;                       ///< Represents the vector capacity
    unsigned m_used;                            ///< Represents the vector used space
    T *m_array;                                      ///< Represents the vector array pointer

    /**
    * @brief Deallocate memory for a given pointer.
    *
    * @param[in] ptr The pointer reference to deallocate.
    */
    void Deallocate( T *&ptr );

    /**
    * @brief Resize the vector by doubling its capacity.
    *
    * Allocates a new array, copies existing elements, and deallocates the old array.
    *
    * @param &capacity the capacity of the current vector's capacity.
    */
    void Resize();

    /**
    * @brief Copy the contents of otherArray to copiedArray.
    *
    * @param[in] copiedArray The array that will be copied to.
    * @param[in] otherArray The array to be used for copying.
    */
    void CopyArray( T *copiedArray, T *otherArray );

    /**
    * @brief Copy the contents of another vector.
    *
    * @param[in] otherVector The vector to be copied from.
    */
    void CopyVector( const Vector &otherVector );

    /**
    * @brief The implementation for InsertObject Method.
    *
    * @param[in] object the object to be inserted into the vector.
    */
    bool Insert( const T &object );

    /**
    * @brief The implementation for DeleteObject Method.
    *
    * @param[in] object the object to be deleted from the vector.
    */
    bool Delete();
};

// ++++++++++++++++++++ PUBLIC ++++++++++++++++++++++++++++++++++++++
template<class T>
Vector<T>::Vector()
{
    m_capacity = INITIAL_CAPACITY;
    m_used = INITIAL_VALUE;
    m_array = new T[INITIAL_CAPACITY];
}

template<class T>
Vector<T>::~Vector()
{
    Deallocate( m_array );
}

template<class T>
Vector<T>::Vector( const Vector &otherVector )
{
    if( otherVector.m_array == nullptr )
    {
        m_array = nullptr;
    }
    if( m_array != nullptr )
    {
        Deallocate( m_array );
    }
    CopyVector( otherVector );
}

template<class T>
Vector<T> &Vector<T>::operator = ( const Vector &otherVector )
{
    if( this != &otherVector )
    {
        if( m_array != nullptr )
        {
            Deallocate( m_array );
        }
        CopyVector( otherVector );
    }
    return *this;
}

template<class T>
unsigned Vector<T>::GetCapacity() const
{
    return m_capacity;
}

template<class T>
unsigned Vector<T>::GetUsed() const
{
    return m_used;
}

template<class T>
T *Vector<T>::Start()
{
    return m_array;
}

template<class T>
T *Vector<T>::Finish()
{
    return m_array + m_used;
}

template<class T>
const T &Vector<T>::operator [] ( const unsigned &index ) const
{
    return m_array[index];
}

template<class T>
T &Vector<T>::operator [] ( const unsigned &index )
{
    return m_array[index];
}

template<class T>
bool Vector<T>::IsEmpty() const
{
    return ( m_used == 0 );
}

template<class T>
bool Vector<T>::InsertObject( const T &object )
{
    return Insert( object );
}

template<class T>
bool Vector<T>::DeleteObject()
{
    return Delete();
}



// ++++++++++++++++++++ PRIVATE +++++++++++++++++++++++++++++++++++++
template<class T>
void Vector<T>::Deallocate( T *&ptr )
{
    if( ptr != nullptr )
    {
        delete [] ptr;
        ptr = nullptr;
    }
}

template<class T>
void Vector<T>::Resize()
{
    unsigned newCapacity = m_capacity * 2;
    T *newArray = new T[newCapacity];
    CopyArray( newArray, m_array );
    Deallocate( m_array );

    m_array = new T[newCapacity];
    CopyArray( m_array, newArray );
    Deallocate( newArray );

    m_capacity = newCapacity;
}

template<class T>
void Vector<T>::CopyArray( T *copiedArray, T *otherArray )
{
    if( copiedArray != nullptr )
    {
        for( unsigned i(0); i<m_used; i++ )
        {
            copiedArray[i] = otherArray[i];
        }
    }
}

template<class T>
void Vector<T>::CopyVector( const Vector &otherVector )
{
    m_capacity = otherVector.m_capacity;
    m_used      = otherVector.m_used;
    m_array     = new T[otherVector.m_capacity];

    CopyArray( m_array, otherVector.m_array );
}

template<class T>
bool Vector<T>::Insert( const T &object )
{
    if( m_used == m_capacity / 2 )
    {
        Resize();
    }
    m_array[m_used] = object;
    m_used ++;
    return true;
}

template<class T>
bool Vector<T>::Delete()
{
    return m_used --;
}

#endif // VECTOR_H_INCLUDED
