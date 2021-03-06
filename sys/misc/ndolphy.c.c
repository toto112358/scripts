/*
 * config data
 */

#include "sys/param.h"
#include "sys/conf.h"
#include "sys/vtimes.h"
#include "sys/proc.h"
#include "sys/inode.h"
#include "sys/file.h"
#include "sys/text.h"
#include "sys/callout.h"
#include "sys/buf.h"
#include "sys/map.h"
#include "sys/stream.h"
#include "sys/mba.h"
#include "sys/mbaddr.h"
#include "sys/nxaddr.h"
#include "sys/nexus.h"
#include "sys/ubaddr.h"
#include "sys/uba.h"
#include "sys/uda.h"
#include "sys/subaddr.h"
#include "sys/dz.h"
#include "sys/dk.h"
#include "sys/kmc.h"
#include "sys/kdi.h"
#include "sys/mscp.h"
#include "sys/udaioc.h"
#include "sys/ra.h"
#include "sys/tu78.h"
#include "sys/hp.h"
#include "sys/bad144.h"
#include "sys/ttyio.h"
#include "sys/ttyld.h"
#include "sys/bufld.h"
#include "sys/mesg.h"
#include "sys/dkp.h"
#include "sys/mount.h"
extern struct bdevsw hpbdev;
extern struct bdevsw swbdev;
extern struct bdevsw rabdev;
extern struct bdevsw tu78bdev;
int nblkdev = 9;
extern struct cdevsw cncdev;
extern struct cdevsw dzcdev;
extern struct cdevsw mmcdev;
extern struct cdevsw hpcdev;
extern struct cdevsw swcdev;
extern struct cdevsw cbscdev;
extern struct cdevsw dkcdev;
extern struct cdevsw tu78cdev;
extern struct cdevsw kmccdev;
extern struct cdevsw racdev;
extern struct cdevsw kdicdev;
extern struct cdevsw fdcdev;
int nchrdev = 41;
extern struct fstypsw fsfs;
extern struct fstypsw nafs;
extern struct fstypsw prfs;
extern struct fstypsw msfs;
extern struct fstypsw nbfs;
extern struct fstypsw erfs;
extern struct fstypsw pipfs;
int nfstyp = 7;
extern struct streamtab ttystream;
extern struct streamtab rdkstream;
extern struct streamtab msgstream;
extern struct streamtab dkpstream;
extern struct streamtab bufldstream;
extern struct streamtab rmsgstream;
extern struct streamtab connstream;
extern struct streamtab xpstream;
int nstreamtab = 20;

struct bdevsw *bdevsw[] = {
	&hpbdev,	/* 0 */
	NULL,
	NULL,
	NULL,
	&swbdev,	/* 4 */
	NULL,
	NULL,
	&rabdev,	/* 7 */
	&tu78bdev,	/* 8 */
};
struct cdevsw *cdevsw[] = {
	&cncdev,	/* 0 */
	&dzcdev,	/* 1 */
	NULL,
	&mmcdev,	/* 3 */
	&hpcdev,	/* 4 */
	NULL,
	NULL,
	&swcdev,	/* 7 */
	&cbscdev,	/* 8 */
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&dkcdev,	/* 17 */
	NULL,
	NULL,
	NULL,
	NULL,
	&tu78cdev,	/* 22 */
	NULL,
	NULL,
	NULL,
	&kmccdev,	/* 26 */
	NULL,
	&racdev,	/* 28 */
	NULL,
	NULL,
	&kdicdev,	/* 31 */
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&fdcdev,	/* 40 */
};
struct fstypsw *fstypsw[] = {
	&fsfs,	/* 0 */
	&nafs,	/* 1 */
	&prfs,	/* 2 */
	&msfs,	/* 3 */
	&nbfs,	/* 4 */
	&erfs,	/* 5 */
	&pipfs,	/* 6 */
};
struct streamtab *streamtab[] = {
	&ttystream,	/* 0 */
	NULL,
	&rdkstream,	/* 2 */
	NULL,
	&msgstream,	/* 4 */
	&dkpstream,	/* 5 */
	NULL,
	&bufldstream,	/* 7 */
	NULL,
	&rmsgstream,	/* 9 */
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&connstream,	/* 18 */
	&xpstream,	/* 19 */
};
int proccnt = 1200;
struct proc proc[1200];
int filecnt = 2500;
struct file file[2500];
int inodecnt = 4000;
struct inode inode[4000];
int calloutcnt = 50;
struct callout callout[50];
int textcnt = 100;
struct text text[100];
int argcnt = 16;
struct map argmap[16];
int swmapcnt = 400;
struct map swapmap[400];
int kernelcnt = 600;
struct map kernelmap[600];
int swbufcnt = 50;
struct buf swapbuf[50];
struct swapinfo swapinfo[50];
int bufhcnt = 127;
struct bufhd bufhash[127];
int queuecnt = 2000;
struct queue queue[2000];
int streamcnt = 500;
struct stdata streams[500];
int blkcnt = 2000;
struct block cblock[2000];
int blkbcnt = 30;
struct buf *cblkbuf[30];
int dstflag = 1;
int timezone = 300;
int maxtsize = 12256;
int maxdsize = 24544;
int maxssize = 24544;

struct nextab nextab[] = {
	0, 8,
	0, 9,
	0, 3,
	-1
};
struct nxaddr mbaaddr[] = {
	{0, 0, 0x0},
	{1, 0, 0x0},
};
int mbacnt = 2;
struct mba mba[2];
extern hp0int();
extern tm780int();
char mbaid[][8] = {
 0, 01, 02, 03, 04, 05, 06, 07,
 0, 011, 012, 013, 014, 015, 016, 017,
};
int mbastray();
int (*mbavec[][8])() = {
 hp0int, mbastray, mbastray, mbastray, mbastray, mbastray, mbastray, mbastray,
 tm780int, mbastray, mbastray, mbastray, mbastray, mbastray, mbastray, mbastray,
};
struct mbaddr hpaddr[] = {
	{0, 0},
};
int hpcnt = 1;
struct hpdisk hpdisk[1];
struct buf hpbuf[1];
struct buf hpbadbuf[1];
struct bad144 hpbad[1];
struct mbaddr tm78addr[] = {
	{0, 1},
};
int tm78cnt = 1;
struct tm78 tm78[1];
struct subaddr tu78addr[] = {
	{0, 0},
};
int tu78cnt = 1;
struct tu78 tu78[1];
struct buf ctu78buf[1];
struct buf rtu78buf[1];
struct nxaddr ubaaddr[] = {
	{2, 0, 0x200},
};
int ubacnt = 1;
struct uba uba[1];
long ubazvec[1];
char *ubavoff[1];
long *ubavreg[1];
struct ubaddr udaddr[] = {
	{0772150, 0450, 0},
};
int udcnt = 1;
struct ud ud[1];
extern struct msportsw udport;
int nmsport = 1;
struct msportsw *msportsw[] = {
	&udport,	/* 0 */
};
struct msaddr raaddr[] = {
	{0, 0, 0},
	{0, 0, 1},
	{0, 0, 2},
	{0, 0, 3},
};
int racnt = 4;
struct radisk radisk[4];
struct buf rabuf[4];
struct ubaddr dzaddr[] = {
	{0760120, 0320, 0},
	{0760130, 0330, 0},
};
int dzcnt = 16;
struct dz dz[16];
struct ubaddr kmcaddr[] = {
	{0760600, 0600, 0},
};
int kmccnt = 1;
struct kmc kmc[1];
struct ubaddr dkaddr[] = {
	{0767770, 0540, 0},
};
int dkcnt = 256;
struct dk dk[256];
char dkstate[256];
int kdicnt = 1;
struct kdikmc kdikmc[1];
struct kmcdk k[1];
int cncnt = 0;
int ttycnt = 32;
struct ttyld ttyld[32];
int msgcnt = 256;
struct imesg mesg[256];
int rdkcnt = 0;
int xpcnt = 0;
int dkpcnt = 128;
struct dkp dkp[128];
int bufldcnt = 32;
struct bufld bufld[32];
int fscnt = 10;
struct mount fsmtab[10];
int rootfstyp = 0;
dev_t rootdev = makedev(7, 64);
dev_t swapdev = makedev(4, 0);
struct swdevt swdevt[] = {
	{makedev(7, 1), 20480L},
	{makedev(7, 9), 20480L},
	{makedev(7, 17), 20480L},
	{makedev(7, 25), 20480L},
};
int nswdevt = 4;
extern int uddump();
int (*dumprout)() = uddump;
int dumpunit = 0;
long dumplow = 10240;
long dumpsize = 20480;
