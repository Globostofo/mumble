/* Copyright (C) 2005, Thorvald Natvig <thorvald@natvig.com>

   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.
   - Neither the name of the Mumble Developers nor the names of its
     contributors may be used to endorse or promote products derived from this
     software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _AUDIOSTATS_H
#define _AUDIOSTATS_H

class AudioEchoWidget : public QGLWidget {
	Q_OBJECT
	public:
		enum Mode { REAL, IMAGINARY, MODULUS, PHASE };
		Mode mode;
		AudioEchoWidget(QWidget *parent);
	protected:
		void initializeGL();
		void resizeGL(int w, int h);
		void paintGL();
};

class AudioNoiseWidget : public QWidget {
	Q_OBJECT
	public:
		AudioNoiseWidget(QWidget *parent);
	protected slots:
		void paintEvent (QPaintEvent *event);
};

class AudioStats : public QDialog {
	Q_OBJECT;
	protected:
		QLabel *qlMicLevel, *qlSpeakerLevel, *qlSignalLevel, *qlMicVolume, *qlMicSNR, *qlSpeechProb, *qlBitrate;
		QMap<QObject *, AudioEchoWidget::Mode> qmEchoMode;
		AudioNoiseWidget *anwNoise;
		AudioEchoWidget *aewEcho;
		QTimer *qtTick;
		bool bTalking;
	public:
		AudioStats(QWidget *parent);
	public slots:
		void on_Tick_timeout();
		void onEchoMode(bool);
};

#else
class AudioStats;
#endif
