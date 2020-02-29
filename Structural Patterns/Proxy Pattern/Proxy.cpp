/*
PROXY

Intent

Provide a surrogate or placeholder for another object to control access to it.
Use an extra level of indirection to support distributed, controlled, or intelligent access.
Add a wrapper and delegation to protect the real component from undue complexity.

Problem
You need to support resource-hungry objects, and you do not want to instantiate such objects unless and until they are actually requested by the client.
*/

//BEFORE

class Image
{
    int m_id;
    static int s_next;
  public:
    Image()
    {
        m_id = s_next++;
        cout << "   $$ ctor: " << m_id << '\n';
    }
    ~Image()
    {
        cout << "   dtor: " << m_id << '\n';
    }
    void draw()
    {
        cout << "   drawing image " << m_id << '\n';
    }
};
int Image::s_next = 1;

int main()
{
  Image images[5];

  for (int i; true;)
  {
    cout << "Exit[0], Image[1-5]: ";
    cin >> i;
    if (i == 0)
      break;
    images[i - 1].draw();
  }
}

/*
OUTPUT:
   $$ ctor: 1
   $$ ctor: 2
   $$ ctor: 3
   $$ ctor: 4
   $$ ctor: 5
Exit[0], Image[1-5]: 2
   drawing image 2
Exit[0], Image[1-5]: 4
   drawing image 4
Exit[0], Image[1-5]: 2
   drawing image 2
Exit[0], Image[1-5]: 0
   dtor: 5
   dtor: 4
   dtor: 3
   dtor: 2
   dtor: 1
*/

//AFTER

/*
Initialization on first use

Design an "extra level of indirection" wrapper class
The wrapper class holds a pointer to the real class
The pointer is initialized to null
When a request comes in, the real object is created "on first use" (aka lazy initialization)
The request is always delegated
*/

class RealImage
{
    int m_id;
  public:
    RealImage(int i)
    {
        m_id = i;
        cout << "   $$ ctor: " << m_id << '\n';
    }
    ~RealImage()
    {
        cout << "   dtor: " << m_id << '\n';
    }
    void draw()
    {
        cout << "   drawing image " << m_id << '\n';
    }
};

// 1. Design an "extra level of indirection" wrapper class
class Image
{
    // 2. The wrapper class holds a pointer to the real class
    RealImage *m_the_real_thing;
    int m_id;
    static int s_next;
  public:
    Image()
    {
        m_id = s_next++;
        // 3. Initialized to null
        m_the_real_thing = 0;
    }
    ~Image()
    {
        delete m_the_real_thing;
    }
    void draw()
    {
        // 4. When a request comes in, the real object is
        //    created "on first use"
        if (!m_the_real_thing)
          m_the_real_thing = new RealImage(m_id);
        // 5. The request is always delegated
        m_the_real_thing->draw();
    }
};
int Image::s_next = 1;

int main()
{
  Image images[5];

  for (int i; true;)
  {
    cout << "Exit[0], Image[1-5]: ";
    cin >> i;
    if (i == 0)
      break;
    images[i - 1].draw();
  }
}


/*
OUTPUT:

Exit[0], Image[1-5]: 2
   $$ ctor: 2
   drawing image 2
Exit[0], Image[1-5]: 4
   $$ ctor: 4
   drawing image 4
Exit[0], Image[1-5]: 2
   drawing image 2
Exit[0], Image[1-5]: 0
   dtor: 4
   dtor: 2


*/