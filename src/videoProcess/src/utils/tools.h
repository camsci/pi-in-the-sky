// tools.h
// Meteor Pi, Cambridge Science Centre
// Dominic Ford

#ifndef TOOLS_H
#define TOOLS_H 1

#include "vidtools/v4l2uvc.h"
#include "png/image.h"

#define CLIP256(X) ( d=X , ((d<0)?0: ((d>255)?255:d) ))

typedef struct videoMetadata
 {
  double tstart, tstop, fps, lng, lat;
  int    width, height, flagGPS, flagUpsideDown, nframe;
  char *cameraId, *videoDevice, *filename;
 } videoMetadata;

void  writeMetadata       (videoMetadata v);
int   nearestMultiple     (double in, int factor);
void  frameInvert         (unsigned char *buffer, int len);
void *videoRecord         (struct vdIn *videoIn, double seconds);
void  snapshot            (struct vdIn *videoIn, int nfr, int zero, double expComp, char *fname, unsigned char *medianRaw);
double calculateSkyClarity(image_ptr *img);
void  medianCalculate     (const int width, const int height, const int medianMapResolution, int *medianWorkspace, unsigned char *medianMap);
int   dumpFrame           (int width, int height, unsigned char *buffer, char *fName);
int   dumpFrameRGB        (int width, int height, unsigned char *bufferRGB, char *fName);
int   dumpFrameRGBFromInts(int width, int height, int *bufferRGB, int nfr, int gain, char *fName);
int   dumpFrameRGBFromISub(int width, int height, int *bufferRGB, int nfr, int gain, unsigned char *buffer2, char *fName);
int   dumpVideo           (int nfr1, int nfr2, int width, int height, unsigned char *buffer1, unsigned char *buffer2, unsigned char *buffer3, char *fName);

#endif

