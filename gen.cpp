#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main() {
  vector<string> operators = {"+", "-", "*", "/", "%", "&", "|", "^", "&&", "||"};
  vector<int> mask =         {  1,   1,   1,   1,   1,   1,   1,   1,    0,    0};   
  for (int i = 0; i < operators.size(); i++) {
    const char* s = operators[i].c_str();
    printf(
        "template <class T, class Q>\n"
        "auto operator%s(const vector2<T>& left, const vector2<Q>& right) -> vector2<decltype(left[0] %s right[0])> const {\n"
        "  vector2<decltype(left[0] %s right[0])> ret(right.size());\n"
        "  if (right.size() != left.size()) {\n"
        "    fprintf(stderr, \"%%s: %%d: Error - summing arrays of different lenght!\\n\", __FILE__, __LINE__);\n"
        "    return ret;\n"
        "  }\n"
        "  for(int i = 0; i < ret.size(); i++) {\n"
        "    ret[i] = left[i] %s right[i];\n"
        "  }\n"
        "  return ret;\n"
        "}\n"
        "\n"
        "template <class T, class Q>\n"
        "auto operator%s(const vector2<T>& left, const Q& right) -> vector2<decltype(left[0] %s right)> const {\n"
        "  vector2<decltype(left[0] %s right)> ret(left);\n"
        "  for(int i = 0; i < ret.size(); i++) {\n"
        "    ret[i] = ret[i] %s  right;\n"
        "  }\n"
        "  return ret;\n"
        "}\n"
        "\n"
        "template <class T, class Q>\n"
        "auto operator%s(const T& left, const vector2<Q>& right) -> vector2<decltype(left %s right[0])> const {\n"
        "  vector2<decltype(left %s right[0])> ret(right);\n"
        "  for(int i = 0; i < ret.size(); i++) {\n"
        "    ret[i] = left %s ret[i];\n"
        "  }\n"
        "  return ret;\n"
        "}\n"
        "\n"
        , s, s, s, s, s, s, s, s, s, s, s, s);
    if (!mask[i])
      continue;
    printf(
        "template <class T, class Q>\n"
        "auto operator%s=(vector2<T>& left, const vector2<Q>& right) -> vector2<decltype(left[0] %s right[0])> {\n"
        "  if (right.size() != left.size()) {\n"
        "    fprintf(stderr, \"%%s: %%d: Error - summing arrays of different lenght!\\n\", __FILE__, __LINE__);\n"
        "    return left;\n"
        "  }\n"
        "  for(int i = 0; i < left.size(); i++) {\n"
        "    left[i] %s= right[i];\n"
        "  }\n"
        "  return left;\n"
        "}\n"
        "\n"
        "template <class T, class Q>\n"
        "auto operator%s=(vector2<T>& left, const Q& right) -> vector2<decltype(left[0] %s right[0])> {\n"
        "  for(int i = 0; i < left.size(); i++) {\n"
        "    left[i] %s= right;\n"
        "  }\n"
        "  return left;\n"
        "}\n"
        "\n"
        , s, s, s, s, s, s);
  }
  printf("#endif  // VECTOR2\n");
}

/*
 * 
 * Original code example:

template <class T, class Q>
auto operator+(const vector2<T>& left, const vector2<Q>& right) -> vector2<decltype(left[0] + right[0])> const {
  vector2<decltype(left[0] + right[0])> ret(right.size());
  if (right.size() != left.size()) {
    fprintf(stderr, "%s: %d: Error - summing arrays of different lenght!\n", __FILE__, __LINE__);
    return ret;
  }
  for(int i = 0; i < ret.size(); i++) {
    ret[i] = left[i] + right[i];
  }
  return ret;
}

template <class T, class Q>
auto operator+(const vector2<T>& left, const Q& right) -> vector2<decltype(left[0] + right)> const {
  vector2<decltype(left[0] + right)> ret(left);
  for(int i = 0; i < ret.size(); i++) {
    ret[i] = ret[i] +  right;
  }
  return ret;
}

template <class T, class Q>
auto operator+(const T& left, const vector2<Q>& right) -> vector2<decltype(left + right[0])> const {
  vector2<decltype(left + right[0])> ret(right);
  for(int i = 0; i < ret.size(); i++) {
    ret[i] = left + ret[i];
  }
  return ret;
}

template <class T, class Q>
auto operator+=(vector2<T>& left, const vector2<Q>& right) -> vector2<decltype(left[0] + right[0])> {
  if (right.size() != left.size()) {
    fprintf(stderr, "%s: %d: Error - summing arrays of different lenght!\n", __FILE__, __LINE__);
    return left;
  }
  for(int i = 0; i < left.size(); i++) {
    left[i] += right[i];
  }
  return left;
}

template <class T, class Q>
auto operator+=(vector2<T>& left, const Q& right) -> vector2<decltype(left[0] + right[0])> {
  for(int i = 0; i < left.size(); i++) {
    left[i] += right;
  }
  return left;
}



#endif  // VECTOR2
*/