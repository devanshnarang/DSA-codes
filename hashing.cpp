//Why Hashing?
/*It halps make searching operation possible in O(1) time complexity
Finding a unique index for all elements to store them is called hashing and the unique index is called hash value
hash function -k mod 10*/


//Different Hash Functions
/*1. Division method-h(k)=k mod m where m is the number of buckets2.Mid square method=k^2 and extract middle digits3.
Digit folding method-fold key into equal size partfor eh k1k2k3k4k5h(k)=k1k2+k3k4+k54. Multipleication method-h(k)=floor(M(kA mod 1)) 
M=number of buckets ,A belongs from 0 to 1for eg-k=12345  A=0.01kA=123.45  kA mod 1=0.45M*kA mod 1=4.5 if M=10floor value will be 4*/


//Collisions
/*When 2 elements have same hash value then it is called collisions.@ ways to tackle collisions are open hashing and closed hashing*/


//Open Hashing(Closed Addressing)-method to handle collision in this is called separate chaining/*In separate chaining we attach element with 
//same hash value using linked list at same locationAdvantages-simpler to implement,table never fills up fullDisadvantages-manyyy 
//buckets may remain empty eventually time complexity may increase*/


//Closed Hashing(Open addressing)
/*Linear probing-in this method we add element at some (h(k)+i)mod 10 value where i varies from 0 to MEg- h(634)=4+0 mod 10 =4 which is 
filled so i will increase and so onProbes-chances used to find the right position*/


//Quadratic probing -store elements at (h(k)+i^2)mod M where i varies from 0 to M,done so that elements don't accumulate near to each other


//Double Hashing
/*In this we use double hash functions and elements are stored at (h1(k)+ih2(k))mod M  where i varies from 0 to M*/


//Load Factor
/*n-number of elements,m-number of bucketsLoad factor-n/m tells avg entries in one bucket;tells load put on each bucket of the table,
if more entries will be there then time complexity will increase of searching*/

/*Whenever load factor exceeds a certain value then we do Rehashing(load factor limit is 0.75)Rehashing means increasing size of hash table 
and redistributing elements in it*/


//if collisions increase then time complexity will also increase

//MOORE'S VOTING ALGORITHM