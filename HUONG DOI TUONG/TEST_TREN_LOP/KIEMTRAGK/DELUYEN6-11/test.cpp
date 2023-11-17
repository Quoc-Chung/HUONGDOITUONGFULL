#include<bits/stdc++.h>
using namespace std;
class Node {
private:
    char data;
    int freq;
    Node* left;
    Node* right;

public:
    Node(char data, int freq) : data(data), freq(freq), left(NULL), right(NULL) {}

    char getData() {
        return data;
    }

    int getFreq() {
        return freq;
    }

    Node* getLeft() {
        return left;
    }

    Node* getRight() {
        return right;
    }

    void setLeft(Node* node) {
        left = node;
    }

    void setRight(Node* node) {
        right = node;
    }
};

class Comparator {
public:
    bool operator()(Node* left, Node* right) {
        return left->getFreq() > right->getFreq();
    }
};

class HuffmanTree {
public:
    Node* XayDungTreeHuffman(map<char, int> freq) {
        priority_queue<Node*, vector<Node*>, Comparator> pq;

        for (map<char, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
            pq.push(new Node(it->first, it->second));
        }

        while (pq.size() != 1) {
            Node* left = pq.top();
            pq.pop();

            Node* right = pq.top();
            pq.pop();

            Node* top = new Node('$', left->getFreq() + right->getFreq());
            top->setLeft(left);
            top->setRight(right);

            pq.push(top);
        }
        return pq.top();
    }

    void TaoMaHuffman(Node* root, string code, map<char, string>& codes) {
        if (root == NULL) return;

        if (root->getData() != '$') {
            codes[root->getData()] = code;
        }

        TaoMaHuffman(root->getLeft(), code + "0", codes);
        TaoMaHuffman(root->getRight(), code + "1", codes);
    }
};

class HuffmanMaHoa {
public:
    string compress(string input, map<char, string> codes) {
        string ChuoiDuocMaHoa = "";
        for (int i = 0; i < input.size(); ++i) {
            char c = input[i];
            ChuoiDuocMaHoa += codes[c];
        }
        return ChuoiDuocMaHoa;
    }
};

class HuffmanGiaiMa {
public:
    string decompress(string input, Node* root) {
        string ChuoiDuocGiaiMa= "";
        Node* current = root;
        for (int i = 0; i < input.size(); ++i) {
            char c = input[i];
            if (c == '0') {
                current = current->getLeft();
            } else {
                current = current->getRight();
            }

            if (current->getData() != '$') {
               ChuoiDuocGiaiMa+= current->getData();
                current = root;
            }
        }
        return ChuoiDuocGiaiMa;
    }
};

int main() {
    HuffmanTree huffmanTree;

    map<char, int> freq;
  
    cout << "\nNhap chuoi can ma hoa : ";
    string s;
    getline(cin, s);

    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (freq.find(c) != freq.end()) {
            freq[c]++;
        } else {
            freq[c] = 1;
        }
    }
    Node* root = huffmanTree.XayDungTreeHuffman(freq);
    map<char, string> codes;
    huffmanTree.TaoMaHuffman(root, "", codes);

    cout << "Ma hoa bang huffman :" << endl;
    for (map<char, string>::iterator it = codes.begin(); it != codes.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }

    HuffmanMaHoa MaHoa;
    HuffmanGiaiMa GiaiMa;

    string ChuoiNen = MaHoa.compress(s, codes);
    cout << "Chuoi nen la: " << ChuoiNen << endl;

    string ChuoiGiaiMa = GiaiMa.decompress(ChuoiNen, root);
    cout << "Chuoi duoc giai ma  la : " << ChuoiGiaiMa << endl;

    return 0;
}




