Output of the generator is below. It Generates all permutations of the product of the base set of transformation matrices for which each transformation appears only once.

The most valueable and widely used permutation in graphics applications is,

```
TRS =
  [ cosR*Sx  -sinR*Sy  tx ]
  [ sinR*Sx  cosR*Sy  ty ]
  [ 0  0  1 ]
```

because the translation is not distorted by the other transformations.

If we include skew, the most commonly used transformation becomes,

```
TRSH =
  [ cosR*Sx+-sinR*Sy*B  cosR*Sx*A+-sinR*Sy  tx ]
  [ sinR*Sx+cosR*Sy*B  sinR*Sx*A+cosR*Sy  ty ]
  [ 0  0  1 ]
```

```
--------------------------------------------------------------------------------
 base transformations
--------------------------------------------------------------------------------

T =
  [ 1  0  tx ]
  [ 0  1  ty ]
  [ 0  0  1 ]


R =
  [ cosR  -sinR  0 ]
  [ sinR  cosR  0 ]
  [ 0  0  1 ]


S =
  [ Sx  0  0 ]
  [ 0  Sy  0 ]
  [ 0  0  1 ]


H =
  [ 1  A  0 ]
  [ B  1  0 ]
  [ 0  0  1 ]

--------------------------------------------------------------------------------
 x2 permutations
--------------------------------------------------------------------------------

TR =
  [ cosR  -sinR  tx ]
  [ sinR  cosR  ty ]
  [ 0  0  1 ]


TS =
  [ Sx  0  tx ]
  [ 0  Sy  ty ]
  [ 0  0  1 ]


TH =
  [ 1  A  tx ]
  [ B  1  ty ]
  [ 0  0  1 ]


RT =
  [ cosR  -sinR  cosR*tx+-sinR*ty ]
  [ sinR  cosR  sinR*tx+cosR*ty ]
  [ 0  0  1 ]


RS =
  [ cosR*Sx  -sinR*Sy  0 ]
  [ sinR*Sx  cosR*Sy  0 ]
  [ 0  0  1 ]


RH =
  [ cosR+-sinR*B  cosR*A+-sinR  0 ]
  [ sinR+cosR*B  sinR*A+cosR  0 ]
  [ 0  0  1 ]


HT =
  [ 1  A  tx+A*ty ]
  [ B  1  B*tx+ty ]
  [ 0  0  1 ]


HS =
  [ Sx  A*Sy  0 ]
  [ B*Sx  Sy  0 ]
  [ 0  0  1 ]


HR =
  [ cosR+A*sinR  -sinR+A*cosR  0 ]
  [ B*cosR+sinR  B*-sinR+cosR  0 ]
  [ 0  0  1 ]


ST =
  [ Sx  0  Sx*tx ]
  [ 0  Sy  Sy*ty ]
  [ 0  0  1 ]


SR =
  [ Sx*cosR  Sx*-sinR  0 ]
  [ Sy*sinR  Sy*cosR  0 ]
  [ 0  0  1 ]


SH =
  [ Sx  Sx*A  0 ]
  [ Sy*B  Sy  0 ]
  [ 0  0  1 ]

--------------------------------------------------------------------------------
 x3 permutations
--------------------------------------------------------------------------------

STR =
  [ Sx*cosR  Sx*-sinR  Sx*tx ]
  [ Sy*sinR  Sy*cosR  Sy*ty ]
  [ 0  0  1 ]


STH =
  [ Sx  Sx*A  Sx*tx ]
  [ Sy*B  Sy  Sy*ty ]
  [ 0  0  1 ]


SRH =
  [ Sx*cosR+Sx*-sinR*B  Sx*cosR*A+Sx*-sinR  0 ]
  [ Sy*sinR+Sy*cosR*B  Sy*sinR*A+Sy*cosR  0 ]
  [ 0  0  1 ]


SRT =
  [ Sx*cosR  Sx*-sinR  Sx*cosR*tx+Sx*-sinR*ty ]
  [ Sy*sinR  Sy*cosR  Sy*sinR*tx+Sy*cosR*ty ]
  [ 0  0  1 ]


SHT =
  [ Sx  Sx*A  Sx*tx+Sx*A*ty ]
  [ Sy*B  Sy  Sy*B*tx+Sy*ty ]
  [ 0  0  1 ]


SHR =
  [ Sx*cosR+Sx*A*sinR  Sx*-sinR+Sx*A*cosR  0 ]
  [ Sy*B*cosR+Sy*sinR  Sy*B*-sinR+Sy*cosR  0 ]
  [ 0  0  1 ]


TRS =
  [ cosR*Sx  -sinR*Sy  tx ]
  [ sinR*Sx  cosR*Sy  ty ]
  [ 0  0  1 ]


TRH =
  [ cosR+-sinR*B  cosR*A+-sinR  tx ]
  [ sinR+cosR*B  sinR*A+cosR  ty ]
  [ 0  0  1 ]


TSR =
  [ Sx*cosR  Sx*-sinR  tx ]
  [ Sy*sinR  Sy*cosR  ty ]
  [ 0  0  1 ]


TSH =
  [ Sx  Sx*A  tx ]
  [ Sy*B  Sy  ty ]
  [ 0  0  1 ]


THR =
  [ cosR+A*sinR  -sinR+A*cosR  tx ]
  [ B*cosR+sinR  B*-sinR+cosR  ty ]
  [ 0  0  1 ]


THS =
  [ Sx  A*Sy  tx ]
  [ B*Sx  Sy  ty ]
  [ 0  0  1 ]


RTS =
  [ cosR*Sx  -sinR*Sy  cosR*tx+-sinR*ty ]
  [ sinR*Sx  cosR*Sy  sinR*tx+cosR*ty ]
  [ 0  0  1 ]


RTH =
  [ cosR+-sinR*B  cosR*A+-sinR  cosR*tx+-sinR*ty ]
  [ sinR+cosR*B  sinR*A+cosR  sinR*tx+cosR*ty ]
  [ 0  0  1 ]


RST =
  [ cosR*Sx  -sinR*Sy  cosR*Sx*tx+-sinR*Sy*ty ]
  [ sinR*Sx  cosR*Sy  sinR*Sx*tx+cosR*Sy*ty ]
  [ 0  0  1 ]


RSH =
  [ cosR*Sx+-sinR*Sy*B  cosR*Sx*A+-sinR*Sy  0 ]
  [ sinR*Sx+cosR*Sy*B  sinR*Sx*A+cosR*Sy  0 ]
  [ 0  0  1 ]


RHS =
  [ cosR+-sinR*B*Sx  cosR*A+-sinR*Sy  0 ]
  [ sinR+cosR*B*Sx  sinR*A+cosR*Sy  0 ]
  [ 0  0  1 ]


RHT =
  [ cosR+-sinR*B  cosR*A+-sinR  cosR+-sinR*B*tx+cosR*A+-sinR*ty ]
  [ sinR+cosR*B  sinR*A+cosR  sinR+cosR*B*tx+sinR*A+cosR*ty ]
  [ 0  0  1 ]


HTS =
  [ Sx  A*Sy  tx+A*ty ]
  [ B*Sx  Sy  B*tx+ty ]
  [ 0  0  1 ]


HTR =
  [ cosR+A*sinR  -sinR+A*cosR  tx+A*ty ]
  [ B*cosR+sinR  B*-sinR+cosR  B*tx+ty ]
  [ 0  0  1 ]


HSR =
  [ Sx*cosR+A*Sy*sinR  Sx*-sinR+A*Sy*cosR  0 ]
  [ B*Sx*cosR+Sy*sinR  B*Sx*-sinR+Sy*cosR  0 ]
  [ 0  0  1 ]


HST =
  [ Sx  A*Sy  Sx*tx+A*Sy*ty ]
  [ B*Sx  Sy  B*Sx*tx+Sy*ty ]
  [ 0  0  1 ]


HRS =
  [ cosR+A*sinR*Sx  -sinR+A*cosR*Sy  0 ]
  [ B*cosR+sinR*Sx  B*-sinR+cosR*Sy  0 ]
  [ 0  0  1 ]


HRT =
  [ cosR+A*sinR  -sinR+A*cosR  cosR+A*sinR*tx+-sinR+A*cosR*ty ]
  [ B*cosR+sinR  B*-sinR+cosR  B*cosR+sinR*tx+B*-sinR+cosR*ty ]
  [ 0  0  1 ]

--------------------------------------------------------------------------------
 x4 permutations
--------------------------------------------------------------------------------

HSTR =
  [ Sx*cosR+A*Sy*sinR  Sx*-sinR+A*Sy*cosR  Sx*tx+A*Sy*ty ]
  [ B*Sx*cosR+Sy*sinR  B*Sx*-sinR+Sy*cosR  B*Sx*tx+Sy*ty ]
  [ 0  0  1 ]


HTSR =
  [ Sx*cosR+A*Sy*sinR  Sx*-sinR+A*Sy*cosR  tx+A*ty ]
  [ B*Sx*cosR+Sy*sinR  B*Sx*-sinR+Sy*cosR  B*tx+ty ]
  [ 0  0  1 ]


HTRS =
  [ cosR+A*sinR*Sx  -sinR+A*cosR*Sy  tx+A*ty ]
  [ B*cosR+sinR*Sx  B*-sinR+cosR*Sy  B*tx+ty ]
  [ 0  0  1 ]


HSRT =
  [ Sx*cosR+A*Sy*sinR  Sx*-sinR+A*Sy*cosR  Sx*cosR+A*Sy*sinR*tx+Sx*-sinR+A*Sy*cosR*ty ]
  [ B*Sx*cosR+Sy*sinR  B*Sx*-sinR+Sy*cosR  B*Sx*cosR+Sy*sinR*tx+B*Sx*-sinR+Sy*cosR*ty ]
  [ 0  0  1 ]


HRST =
  [ cosR+A*sinR*Sx  -sinR+A*cosR*Sy  cosR+A*sinR*Sx*tx+-sinR+A*cosR*Sy*ty ]
  [ B*cosR+sinR*Sx  B*-sinR+cosR*Sy  B*cosR+sinR*Sx*tx+B*-sinR+cosR*Sy*ty ]
  [ 0  0  1 ]


HRTS =
  [ cosR+A*sinR*Sx  -sinR+A*cosR*Sy  cosR+A*sinR*tx+-sinR+A*cosR*ty ]
  [ B*cosR+sinR*Sx  B*-sinR+cosR*Sy  B*cosR+sinR*tx+B*-sinR+cosR*ty ]
  [ 0  0  1 ]


TRSH =
  [ cosR*Sx+-sinR*Sy*B  cosR*Sx*A+-sinR*Sy  tx ]
  [ sinR*Sx+cosR*Sy*B  sinR*Sx*A+cosR*Sy  ty ]
  [ 0  0  1 ]


TRHS =
  [ cosR+-sinR*B*Sx  cosR*A+-sinR*Sy  tx ]
  [ sinR+cosR*B*Sx  sinR*A+cosR*Sy  ty ]
  [ 0  0  1 ]


TSRH =
  [ Sx*cosR+Sx*-sinR*B  Sx*cosR*A+Sx*-sinR  tx ]
  [ Sy*sinR+Sy*cosR*B  Sy*sinR*A+Sy*cosR  ty ]
  [ 0  0  1 ]


TSHR =
  [ Sx*cosR+Sx*A*sinR  Sx*-sinR+Sx*A*cosR  tx ]
  [ Sy*B*cosR+Sy*sinR  Sy*B*-sinR+Sy*cosR  ty ]
  [ 0  0  1 ]


THRS =
  [ cosR+A*sinR*Sx  -sinR+A*cosR*Sy  tx ]
  [ B*cosR+sinR*Sx  B*-sinR+cosR*Sy  ty ]
  [ 0  0  1 ]


THSR =
  [ Sx*cosR+A*Sy*sinR  Sx*-sinR+A*Sy*cosR  tx ]
  [ B*Sx*cosR+Sy*sinR  B*Sx*-sinR+Sy*cosR  ty ]
  [ 0  0  1 ]


RTSH =
  [ cosR*Sx+-sinR*Sy*B  cosR*Sx*A+-sinR*Sy  cosR*tx+-sinR*ty ]
  [ sinR*Sx+cosR*Sy*B  sinR*Sx*A+cosR*Sy  sinR*tx+cosR*ty ]
  [ 0  0  1 ]


RTHS =
  [ cosR+-sinR*B*Sx  cosR*A+-sinR*Sy  cosR*tx+-sinR*ty ]
  [ sinR+cosR*B*Sx  sinR*A+cosR*Sy  sinR*tx+cosR*ty ]
  [ 0  0  1 ]


RSTH =
  [ cosR*Sx+-sinR*Sy*B  cosR*Sx*A+-sinR*Sy  cosR*Sx*tx+-sinR*Sy*ty ]
  [ sinR*Sx+cosR*Sy*B  sinR*Sx*A+cosR*Sy  sinR*Sx*tx+cosR*Sy*ty ]
  [ 0  0  1 ]


RSHT =
  [ cosR*Sx+-sinR*Sy*B  cosR*Sx*A+-sinR*Sy  cosR*Sx+-sinR*Sy*B*tx+cosR*Sx*A+-sinR*Sy*ty ]
  [ sinR*Sx+cosR*Sy*B  sinR*Sx*A+cosR*Sy  sinR*Sx+cosR*Sy*B*tx+sinR*Sx*A+cosR*Sy*ty ]
  [ 0  0  1 ]


RHST =
  [ cosR+-sinR*B*Sx  cosR*A+-sinR*Sy  cosR+-sinR*B*Sx*tx+cosR*A+-sinR*Sy*ty ]
  [ sinR+cosR*B*Sx  sinR*A+cosR*Sy  sinR+cosR*B*Sx*tx+sinR*A+cosR*Sy*ty ]
  [ 0  0  1 ]


RHTS =
  [ cosR+-sinR*B*Sx  cosR*A+-sinR*Sy  cosR+-sinR*B*tx+cosR*A+-sinR*ty ]
  [ sinR+cosR*B*Sx  sinR*A+cosR*Sy  sinR+cosR*B*tx+sinR*A+cosR*ty ]
  [ 0  0  1 ]


STHR =
  [ Sx*cosR+Sx*A*sinR  Sx*-sinR+Sx*A*cosR  Sx*tx ]
  [ Sy*B*cosR+Sy*sinR  Sy*B*-sinR+Sy*cosR  Sy*ty ]
  [ 0  0  1 ]


STRH =
  [ Sx*cosR+Sx*-sinR*B  Sx*cosR*A+Sx*-sinR  Sx*tx ]
  [ Sy*sinR+Sy*cosR*B  Sy*sinR*A+Sy*cosR  Sy*ty ]
  [ 0  0  1 ]


SRHT =
  [ Sx*cosR+Sx*-sinR*B  Sx*cosR*A+Sx*-sinR  Sx*cosR+Sx*-sinR*B*tx+Sx*cosR*A+Sx*-sinR*ty ]
  [ Sy*sinR+Sy*cosR*B  Sy*sinR*A+Sy*cosR  Sy*sinR+Sy*cosR*B*tx+Sy*sinR*A+Sy*cosR*ty ]
  [ 0  0  1 ]


SRTH =
  [ Sx*cosR+Sx*-sinR*B  Sx*cosR*A+Sx*-sinR  Sx*cosR*tx+Sx*-sinR*ty ]
  [ Sy*sinR+Sy*cosR*B  Sy*sinR*A+Sy*cosR  Sy*sinR*tx+Sy*cosR*ty ]
  [ 0  0  1 ]


SHTR =
  [ Sx*cosR+Sx*A*sinR  Sx*-sinR+Sx*A*cosR  Sx*tx+Sx*A*ty ]
  [ Sy*B*cosR+Sy*sinR  Sy*B*-sinR+Sy*cosR  Sy*B*tx+Sy*ty ]
  [ 0  0  1 ]


SHRT =
  [ Sx*cosR+Sx*A*sinR  Sx*-sinR+Sx*A*cosR  Sx*cosR+Sx*A*sinR*tx+Sx*-sinR+Sx*A*cosR*ty ]
  [ Sy*B*cosR+Sy*sinR  Sy*B*-sinR+Sy*cosR  Sy*B*cosR+Sy*sinR*tx+Sy*B*-sinR+Sy*cosR*ty ]
  [ 0  0  1 ]

```