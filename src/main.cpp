/*
---------------------------------------
2D Transformation Permutation Generator
---------------------------------------

Consider the 4 transformation matrices: translation, rotation, scale and skew. For the 2D
case these can be written in the column-major form,

      [ 1 0 tx ]
  T = [ 0 1 ty ]   (translation matrix T)
      [ 0 0 1  ]

      [ Sx 0  0 ]
  S = [ 0  Sy 0 ]   (scale matrix S)
      [ 0  0  1 ]

      [ cosR -sinR 0 ]
  R = [ sinR  cosR 0 ]   (rotation matrix R)
      [ 0     0    1 ]

      [ 1 A 0 ]
  H = [ B 1 0 ]   (skew matrix H)
      [ 0 0 1 ]

This little program generates all the permutations of the products of these martrices, for
which each transformation appears once in the product, i.e. we discard products like RTRT.

products of 2 matrices
----------------------

TR
TS
TH

RT
RS
RH

HT
HS
HR

ST
SR
SH

total 12

products of 3 matrices
----------------------

TRS
TRH
TSR
TSH
THR
THS

RTS
RTH
RST
RSH
RHS
RHT

HTS
HTR
HSR
HST
HRS
HRT

STH
STR
SRH
SRT
SHT
SHR

total 24

products of 4 matrices
----------------------

TRSH
TRHS
TSRH
TSHR
THRS
THSR

RTSH
RTHS
RSTH
RSHT
RHST
RHTS

HTSR
HTRS
HSRT
HSTR
HRST
HRTS

STHR
STRH
SRHT
SRTH
SHTR
SHRT

total 24

*/

#include <string>
#include <array>
#include <map>
#include <format>
#include <string>
#include <regex>
#include <iostream>
#include <fstream>

std::string generate_permutations(bool apply_simplifications) {

    using column = std::array<std::string, 3>;
    using matrix = std::array<column, 3>;

    matrix T =
    {
        column{"1", "0", "0"},
        column{"0", "1", "0"},
        column{"tx", "ty", "1"},
    };

    matrix R =
    {
        column{"cosR", "sinR", "0"},
        column{"-sinR", "cosR", "0"},
        column{"0", "0", "1"},
    };

    matrix S =
    {
        column{"Sx", "0", "0"},
        column{"0", "Sy", "0"},
        column{"0", "0", "1"},
    };

    matrix H =
    {
        column{"1", "B", "0"},
        column{"A", "1", "0"},
        column{"0", "0", "1"},
    };

    std::map<char, matrix> transforms;
    transforms['T'] = T;
    transforms['R'] = R;
    transforms['S'] = S;
    transforms['H'] = H;

    std::array<std::string, 12> x2_perms{
        "TR",
        "TS",
        "TH",
        "RT",
        "RS",
        "RH",
        "HT",
        "HS",
        "HR",
        "ST",
        "SR",
        "SH"
    };

    std::array<std::string, 24> x3_perms{
        "STR",
        "STH",
        "SRH",
        "SRT",
        "SHT",
        "SHR",
        "TRS",
        "TRH",
        "TSR",
        "TSH",
        "THR",
        "THS",
        "RTS",
        "RTH",
        "RST",
        "RSH",
        "RHS",
        "RHT",
        "HTS",
        "HTR",
        "HSR",
        "HST",
        "HRS",
        "HRT"
    };

    std::array<std::string, 24> x4_perms{
        "HSTR",
        "HTSR",
        "HTRS",
        "HSRT",
        "HRST",
        "HRTS",
        "TRSH",
        "TRHS",
        "TSRH",
        "TSHR",
        "THRS",
        "THSR",
        "RTSH",
        "RTHS",
        "RSTH",
        "RSHT",
        "RHST",
        "RHTS",
        "STHR",
        "STRH",
        "SRHT",
        "SRTH",
        "SHTR",
        "SHRT"
    };

    auto mul = [] (const matrix& a, const matrix& b) -> matrix {

        // The 3x3 matrix product c = a x b is,
        //
        //      (a)         (b)            (c)
        // [ ax bx cx ] [ dx ex fx ]   [ gx hx ix ]
        // [ ay by cy ] [ dy ey fy ] = [ gy hy iy ]
        // [ az bz cz ] [ dz ez fz ]   [ gz hz iz ]
        //
        // gx = ax * dx + bx * dy + cx * dz
        // gy = ay * dx + by * dy + cy * dz
        // gz = az * dz + bz * dy + cz * dz
        // hx = ax * ex + bx * ey + cx * ez
        // hy = ay * ex + by * ey + cy * ez
        // hz = az + ez + bz * ey + cz * ez
        // ix = ax * fx + bx * fy + cx * fz
        // iy = ay * fx + by * fy + cy * fz
        // iz = az * fz + bz * fy + cz * fz

        const std::string& ax = a[0][0];
        const std::string& ay = a[0][1];
        const std::string& az = a[0][2];

        const std::string& bx = a[1][0];
        const std::string& by = a[1][1];
        const std::string& bz = a[1][2];

        const std::string& cx = a[2][0];
        const std::string& cy = a[2][1];
        const std::string& cz = a[2][2];

        const std::string& dx = b[0][0];
        const std::string& dy = b[0][1];
        const std::string& dz = b[0][2];

        const std::string& ex = b[1][0];
        const std::string& ey = b[1][1];
        const std::string& ez = b[1][2];

        const std::string& fx = b[2][0];
        const std::string& fy = b[2][1];
        const std::string& fz = b[2][2];

        matrix c;

        std::string& gx = c[0][0];
        std::string& gy = c[0][1];
        std::string& gz = c[0][2];

        std::string& hx = c[1][0];
        std::string& hy = c[1][1];
        std::string& hz = c[1][2];

        std::string& ix = c[2][0];
        std::string& iy = c[2][1];
        std::string& iz = c[2][2];

        auto mul = [] (const std::string& lhs, const std::string& rhs) -> std::string {
            return lhs + "*" + rhs;
        };

        gx = mul(ax, dx) + "+" + mul(bx, dy) + "+" + mul(cx, dz);
        gy = mul(ay, dx) + "+" + mul(by, dy) + "+" + mul(cy, dz);
        gz = mul(az, dz) + "+" + mul(bz, dy) + "+" + mul(cz, dz);
        hx = mul(ax, ex) + "+" + mul(bx, ey) + "+" + mul(cx, ez);
        hy = mul(ay, ex) + "+" + mul(by, ey) + "+" + mul(cy, ez);
        hz = mul(az, ez) + "+" + mul(bz, ey) + "+" + mul(cz, ez);
        ix = mul(ax, fx) + "+" + mul(bx, fy) + "+" + mul(cx, fz);
        iy = mul(ay, fx) + "+" + mul(by, fy) + "+" + mul(cy, fz);
        iz = mul(az, fz) + "+" + mul(bz, fy) + "+" + mul(cz, fz);

        return c;
    };

    constexpr std::string_view matrix_fmt = R"(
{} =
  [ {}  {}  {} ]
  [ {}  {}  {} ]
  [ {}  {}  {} ]

)";

    std::string result;
    auto print = [&] (std::string_view s) {
        result += s;
    };

    print("================================================================================\n");
    print(apply_simplifications ? " Simplified Permutations\n" : " Raw Permutations\n");
    print("================================================================================\n");

    auto print_matrix = [&] (std::string_view perm, const matrix& m) {

        const std::string& ax = m[0][0];
        const std::string& ay = m[0][1];
        const std::string& az = m[0][2];

        const std::string& bx = m[1][0];
        const std::string& by = m[1][1];
        const std::string& bz = m[1][2];

        const std::string& cx = m[2][0];
        const std::string& cy = m[2][1];
        const std::string& cz = m[2][2];

        print(std::format(matrix_fmt, perm, ax, bx, cx, ay, by, cy, az, bz, cz));
    };

    std::regex x_by_zero_regex_no_brackets{R"([\w-]+\*0)"};
    std::regex zero_by_x_regex_no_brackets{R"(0\*[\w-]+)"};

    std::regex x_by_zero_regex_brackets{R"(\([\w+*]+\)\*0)"};
    std::regex zero_by_x_regex_brackets{R"(0\*\([\w+*]+\))"};

    auto strip_matrix_zero_terms = [&] (matrix& m, bool brackets) {
        for (column& c : m) {
            for (std::string& e : c) {
                if (brackets) {
                    e = std::regex_replace(e, x_by_zero_regex_brackets, "0");
                    e = std::regex_replace(e, zero_by_x_regex_brackets, "0");
                } else {
                    e = std::regex_replace(e, x_by_zero_regex_no_brackets, "0");
                    e = std::regex_replace(e, zero_by_x_regex_no_brackets, "0");
                }
            }
        }
    };

    std::regex zero_plus_x_regex{R"(0\+)"};
    std::regex x_plus_zero_regex{R"(\+0)"};

    auto strip_matrix_zero_plus_terms = [&] (matrix& m) {
        for (column& c : m) {
            for (std::string& e : c) {
                e = std::regex_replace(e, zero_plus_x_regex, "");
                e = std::regex_replace(e, x_plus_zero_regex, "");
            }
        }
    };

    std::regex x_by_one_regex_no_brackets{R"(([\w-]+)(\*1))"};
    std::regex one_by_x_regex_no_brackets{R"((1\*)([\w-]+))"};

    std::regex x_by_one_regex_brackets{R"((\([\w+*]+\))(\*1))"};
    std::regex one_by_x_regex_brackets{R"((1\*)(\([\w+*]+\)))"};

    auto simplify_matrix_one_terms = [&] (matrix& m, bool brackets) {
        for (column& c : m) {
            for (std::string& e : c) {
                if (brackets) {
                    e = std::regex_replace(e, x_by_one_regex_brackets, "$1");
                    e = std::regex_replace(e, one_by_x_regex_brackets, "$2");
                } else {
                    e = std::regex_replace(e, x_by_one_regex_no_brackets, "$1");
                    e = std::regex_replace(e, one_by_x_regex_no_brackets, "$2");
                }
            }
        }
    };

    std::regex brackets_regex{R"([\(\)])"};

    auto strip_brackets = [&] (matrix& m) {
        for (column& c : m) {
            for (std::string& e : c) {
                e = std::regex_replace(e, brackets_regex, "");
            }
        }
    };

    auto add_brackets = [&] (matrix& m) {
        for (column& c : m) {
            for (std::string& e : c) {
                e = '(' + e + ')';
            }
        }
    };

    auto simplify_matrix = [&] (matrix& m, bool brackets) {
        if (apply_simplifications) {
            strip_matrix_zero_terms(m, brackets);
            strip_matrix_zero_plus_terms(m);
            simplify_matrix_one_terms(m, brackets);
        }
    };

    print("--------------------------------------------------------------------------------\n");
    print(" base transformations\n");
    print("--------------------------------------------------------------------------------\n");

    print_matrix("T", T);
    print_matrix("R", R);
    print_matrix("S", S);
    print_matrix("H", H);

    print("--------------------------------------------------------------------------------\n");
    print(" x2 permutations\n");
    print("--------------------------------------------------------------------------------\n");

    for (const auto& perm : x2_perms) {
        const matrix& lhs = transforms.at(perm.at(0));
        const matrix& rhs = transforms.at(perm.at(1));

        matrix c = mul(lhs, rhs);
        simplify_matrix(c, false);
        print_matrix(perm, c);
    }

    print("--------------------------------------------------------------------------------\n");
    print(" x3 permutations\n");
    print("--------------------------------------------------------------------------------\n");

    for (const auto& perm : x3_perms) {

        matrix c;
        {
            const matrix& lhs = transforms.at(perm.at(0));
            const matrix& rhs = transforms.at(perm.at(1));
            c = mul(lhs, rhs);
            simplify_matrix(c, false);
        }
        {
            const matrix& rhs = transforms.at(perm.at(2));
            add_brackets(c);
            matrix d = mul(c, rhs);
            simplify_matrix(d, true);
            strip_brackets(d);
            simplify_matrix(d, false);
            print_matrix(perm, d);
        }
    }

    print("--------------------------------------------------------------------------------\n");
    print(" x4 permutations\n");
    print("--------------------------------------------------------------------------------\n");

    for (const auto& perm : x4_perms) {

        matrix c;
        {
            const matrix& lhs = transforms.at(perm.at(0));
            const matrix& rhs = transforms.at(perm.at(1));
            c = mul(lhs, rhs);
            simplify_matrix(c, false);
        }
        matrix d;
        {
            const matrix& rhs = transforms.at(perm.at(2));
            add_brackets(c);
            d = mul(c, rhs);
            simplify_matrix(d, true);
            strip_brackets(d);
            simplify_matrix(d, false);
        }
        {
            const matrix& rhs = transforms.at(perm.at(3));
            add_brackets(d);
            matrix e = mul(d, rhs);
            simplify_matrix(e, true);
            strip_brackets(e);
            simplify_matrix(e, false);
            simplify_matrix(e, false);
            print_matrix(perm, e);
        }
    }

    return result;
}

int main() {
    std::string res;
    res += generate_permutations(true);
    res += generate_permutations(false);

    std::ofstream file{"permutations.txt", std::ios::trunc};
    if (!file.is_open()) {
        std::cerr << "failed to open file to write to!" << std::endl;
        std::exit(-1);
    }

    file.write(res.data(), res.size());
    file.close();
}