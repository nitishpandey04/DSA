#include <string>

using namespace std;

template <typename V>
class MapNode {
    public:
    string key;
    V value;
    MapNode<V>* next;
    MapNode(string k, V v) {
        key = k;
        value = v;
        next = NULL;
    }
    ~MapNode() {
        delete next;
    }
};

template <typename V>
class OurMap {
    MapNode<V>** buckets;
    int count;
    int bucketsize;
    public:
    OurMap() {
        count = 0;
        bucketsize = 5;
        buckets = new MapNode<V>*[bucketsize];
        for (int i = 0 ; i < bucketsize ; i ++) {
            buckets[i] = NULL;
        }
    }

    ~OurMap() {
        for (int i = 0 ; i < bucketsize ; i ++) {
            delete buckets[i];
        }
        delete [] buckets;
    }

    private:
    int getBucketIndex(string key) {
        int hashcode = 0;
        int p = 1;
        for (int i = key.size() - 1 ; i >= 0 ; i --) {
            hashcode += ((int) key[i]) * p;
            hashcode = hashcode % bucketsize;
            p *= 37; 
            p = p % bucketsize;
        }
        return hashcode % bucketsize;
    }

    void rehash() {
        MapNode<V>** oldbuckets = buckets;
        MapNode<V>** newbuckets = new MapNode<V>*[bucketsize * 2];
        for (int i = 0 ; i < 2 * bucketsize ; i ++) {
            newbuckets[i] = NULL;
        }
        int oldbucketsize = bucketsize;
        buckets = newbuckets;
        bucketsize *= 2;
        count = 0;
        for (int i = 0 ; i < oldbucketsize ; i ++) {
            MapNode<V>* head = oldbuckets[i];
            while (head != NULL) {
                insert(head -> key, head -> value);
                head = head -> next;
            }
            head = oldbuckets[i];
            delete head;
        }
        delete [] oldbuckets;
    }

    public:

    double get_loadfactor() {
        return 1.0 * count / bucketsize;
    }

    void print() {
        for (int i = 0 ; i < bucketsize ; i ++) {
            MapNode<V>* head = buckets[i];
            while (head != NULL) {
                cout << head -> key << " " << head -> value << "\n";
                head = head -> next;
            }
        }
    }

    int size() {
        return count;
    }

    void insert(string key, V v) {
        int index = getBucketIndex(key);
        MapNode<V>* head = buckets[index];
        while (head != NULL) {
            if (head -> key == key) {
                head -> value = v;
                return;
            }
            head = head -> next;
        }
        head = buckets[index];
        MapNode<V>* newNode = new MapNode<V>(key, v);
        newNode -> next = head;
        buckets[index] = newNode;
        count ++;
        double load_factor = 1.0 * count / bucketsize;
        if (load_factor > 0.7) rehash();
    }

    void remove(string key) {
        int index = getBucketIndex(key);
        MapNode<V>* prev = NULL;
        MapNode<V>* head = buckets[index];
        while (head != NULL) {
            if (head -> key == key) {
                if (prev == NULL) {
                    buckets[index] = head -> next;
                } else prev -> next = head -> next;
                head -> next = NULL;
                delete head;
                count --;
                return;
            }
            prev = head;
            head = head -> next;
        }
    }

    V getValue(string key) {
        int index = getBucketIndex(key);
        MapNode<V>* head = buckets[index];
        while (head != NULL) {
            if (head -> key == key) return head -> value;
            head = head -> next;
        }
        return 0;
    }
};
