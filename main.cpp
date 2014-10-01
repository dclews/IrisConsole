#include <QCoreApplication>
#include <IrcConnection>
#include <iris/Bot.hpp>
#include <iris/CommandPlugin.hpp>
#include <QDir>
#include <QPluginLoader>

void loadPlugins(QDir pluginsDir, iris::Bot& bot)
{
	qDebug() << "Searching for plugins in folder:" << pluginsDir.absolutePath();

	foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
		QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
		QObject* plugin = loader.instance();

		if (plugin)
		{
			qDebug() << "\nFound plugin:" << fileName;

			CommandPlugin* commandPlugin = qobject_cast<CommandPlugin*>(plugin);
			if(commandPlugin)
			{
				bot.registerCommandPlugin(commandPlugin);
			}
		}
		else
		{
			qDebug() << "Invalid plugin." << loader.errorString();
		}
	}
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QString name("Iris");
	iris::Bot bot;

	loadPlugins(QDir("/usr/local/share/iris/plugins/"), bot);

	bot.setUserName(name);
	bot.setNickName(name);
	bot.setRealName(name);
	bot.setHost("irc.w3.org");
	bot.setPort(6665);
	bot.joinChannel("#iris");
	bot.open();

	return a.exec();
}
